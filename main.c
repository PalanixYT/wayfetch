#include <stdio.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <stdlib.h>
#define COLOR CYAN
#define NAMECOLOR COLOR
#include "config.h"
#include <dirent.h>

#include "color.h"


struct utsname u;
struct sysinfo sys;

char info[ELEMENTS+1][150];
int i;

void os() {
		FILE *os = fopen("/etc/os-release","r");
		char buffer[150];
		fscanf(os, "NAME=\"%[^\"]+", buffer);
		snprintf(info[i], 149, COLOR"OS"SEPARATOR" "CLOSE"%s %s", buffer, u.machine);
		fclose(os);
		i += 1;
}

void host() {
		FILE *host = fopen("/sys/devices/virtual/dmi/id/product_name", "r");
		char buffer[150];
		fscanf(host, "%s", buffer);
		snprintf( info[i], 149, COLOR"Host"SEPARATOR" "CLOSE"%s", buffer);
		fclose(host);
}

void hname() {
		char h[50];
		char buffer[100];
		gethostname(h);
		getlogin_r(buffer);
		snprintf(info[i], 149, NAMECOLOR"%s"CLOSE"@"NAMECOLOR"%s"CLOSE, buffer, h);
				snprintf(info[i+1], strlen(info[i]) +1 - 2*strlen(CLOSE) - 2*strlen(COLOR), "%s", "-----------------------------------------------------------------------------");
		i += 2;

}

void kernel() {
		snprintf(info[i], 149, COLOR"Kernel"SEPARATOR" "CLOSE"%s", u.release);
		i += 1;
}

void get_up() {
		float mins = sys.uptime / 60;
		if((int) (mins / 60) == 0) {
				snprintf(info[i], 149, COLOR"Uptime"SEPARATOR" "CLOSE"%d mins", (int)mins % 60);
		} else {
		snprintf(info[i], 149, COLOR"Uptime"SEPARATOR" "CLOSE"%d hours, %d mins", (int)(mins / 60), (int)mins % 60);
		}
		i += 1;
}

void get_shell() {
		snprintf(info[i], 149, COLOR"Shell"SEPARATOR" "CLOSE"%s", strrchr(getenv("SHELL"), '/') + 1);
		i += 1;
}

void spacing() {
		strcpy(info[i],"");
		i += 1;
}

void get_term() {
		snprintf(info[i], 149, COLOR"Terminal"SEPARATOR" "CLOSE"%s", getenv("TERM"));
		i += 1;
}

void get_cpu() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r"); /* read from cpu info */

    char *cpu_model = malloc(75);
    char *line = NULL;
    size_t len; /* unused */
    int num_cores = 0, cpu_freq, prec = 3;
    double freq;
    char freq_unit[] = "GHz";

    /* read the model name into cpu_model, and increment num_cores every time model name is found */
    while(getline(&line, &len, cpuinfo) != -1) {
        num_cores += sscanf(line, "model name	: %[^\n@]", cpu_model);
    }
    free(line);
    fclose(cpuinfo);

    FILE *cpufreq = fopen("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq", "r");
    line = NULL;

    if (cpufreq != NULL) {
        if (getline(&line, &len, cpufreq) != -1) {
            sscanf(line, "%d", &cpu_freq);
            cpu_freq /= 1000; // convert kHz to MHz
        } else {
            fclose(cpufreq);
            free(line);
            goto cpufreq_fallback;
        }
    } else {
cpufreq_fallback:
        cpufreq = fopen("/proc/cpuinfo", "r"); /* read from cpu info */

        while (getline(&line, &len, cpufreq) != -1) {
            if (sscanf(line, "cpu MHz : %lf", &freq) > 0) break;
        }

        cpu_freq = (int) freq;
    }

    free(line);
    fclose(cpufreq);

        freq = cpu_freq / 1000.0; // convert MHz to GHz and cast to double

        while (cpu_freq % 10 == 0) {
            --prec;
            cpu_freq /= 10;
        }

        if (prec == 0) prec = 1; // we don't want zero decimal places




		snprintf(info[i], 150, COLOR"CPU"SEPARATOR" "CLOSE"%s (%d) @ %.*f%s", cpu_model, num_cores, prec, freq, freq_unit);
    free(cpu_model);
	i += 1;
}

void get_memory() {
		FILE *mem = fopen("/proc/meminfo","r");
		char *line = NULL;
		size_t len;

		int total_memory, used_memory, total, shared, memfree, buffers, cached, reclaimable;

		while(getline(&line, &len, mem) != -1) {
				sscanf(line, "MemTotal: %d", &total);
				sscanf(line, "Shmem: %d", &shared);
				sscanf(line, "MemFree: %d", &memfree);
				sscanf(line, "Buffers: %d", &buffers);
				sscanf(line, "Cached: %d", &cached);
				sscanf(line, "SReclaimable: %d", &reclaimable);
		}

		free(line);

		fclose(mem);

		used_memory = (total + shared - memfree - buffers - cached - reclaimable) / 1024;
		total_memory = total / 1024;
		int percentage = (int) (100 * (used_memory / (double) total_memory));

		snprintf( info[i], 149, COLOR"Memory"SEPARATOR" "CLOSE"%dMiB / %dMiB (%d%%)", used_memory, total_memory, percentage);
		i += 1;

}

void get_colors() {
    char *s = info[i];

    for(int i = 0; i < 8; i++) {
        sprintf(s, "\e[4%dm   ", i);
        s += 8;
    }
    snprintf(s, 5, "\e[0m");
	i += 1;
}

void get_colors2() {
		char *s = info[i];
    for(int i = 8; i < 16; i++) {
        sprintf(s, "\e[48;5;%dm   ", i);
        s += 12 + (i >= 10 ? 1 : 0);
    }
    snprintf(s, 5, "\e[0m");
	i += 1;
}
void get_packages() {
    int num_packages = 0;
    DIR * dirp;
    struct dirent *entry;

    dirp = opendir(PACDIR);

    if(dirp == NULL) {
		printf("dir doesn't exist");
    } else {

    while((entry = readdir(dirp)) != NULL) {
        if(entry->d_type == DT_DIR) num_packages++;
    }
    num_packages -= 2; // accounting for . and ..

    closedir(dirp);

    snprintf(info[i], 150, COLOR"Packages"SEPARATOR" "CLOSE"%d", num_packages);
	i += 1;
	}
}
void get_wm() {
		snprintf(info[i], 150, COLOR"DE/WM"SEPARATOR" "CLOSE"%s", getenv("XDG_CURRENT_DESKTOP"));
		i += 1;
}
int main() {
		uname(&u);
		sysinfo(&sys);
		order();
		int j = 0;
		for(; j < ROWS && j < i; j++) {
				printf(COLOR "%s   " CLOSE , logo[j]);
				printf("%s\n", info[j]);
		}
		if(ROWS == i) {
		} else if( ROWS < i) {
		for(; j < i; j++) {
				printf("%s   ", logo[ROWS]);
				printf("%s\n", info[j]);
		} }
		else {
		for(; j < ROWS; j++) {
				printf(COLOR "%s   " CLOSE , logo[j]);
				printf("%s\n", info[i]);
				}}
		printf("\n");
		return 0;
}
