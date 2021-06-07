#include <stdio.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"
#include <dirent.h>

//COLORS
#define BLACK "\033[1;30m"
#define RED  "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE  "\033[1;34m"
#define MAGENTA  "\033[1;35m"
#define CYAN  "\033[1;36m"
#define WHITE  "\033[1;37m"

#define CLOSE "\033[0m"


struct utsname u;
struct sysinfo sys;


void os(char p[]) {
		FILE *os = fopen("/etc/os-release","r");
		char buffer[150];
		fscanf(os, "NAME=\"%[^\"]+", buffer);
		snprintf(p, 149, COLOR"OS: "CLOSE"%s %s", buffer, u.machine);
		fclose(os);
}

void host(char c[]) {
		FILE *host = fopen("/sys/devices/virtual/dmi/id/product_name", "r");
		char buffer[150];
		fscanf(host, "%s", buffer);
		snprintf( c, 149, COLOR"Host: "CLOSE"%s", buffer);
		fclose(host);


}

void hname(char n[], char t[]) {
		char h[50];
		char buffer[100];
		gethostname(h);
		getlogin_r(buffer);
		snprintf(n, 149, COLOR"%s"CLOSE"@"COLOR"%s"CLOSE, buffer, h);
				snprintf(t, strlen(n) +1 - 2*strlen(CLOSE) - 2*strlen(COLOR), "%s", "-----------------------------------------------------------------------------");

}

void kernel(char y[]) {
		snprintf(y, 149, COLOR"Kernel: "CLOSE"%s", u.release);
}

void get_up(char e[]) {
		float mins = sys.uptime / 60;
		if((int) (mins / 60) == 0) {
				snprintf(e, 149, COLOR"Uptime: "CLOSE"%d mins", (int)mins % 60);
		} else {
		snprintf(e, 149, COLOR"Uptime: "CLOSE"%d hours, %d mins", (int)(mins / 60), (int)mins % 60);
		}
}

void get_shell(char s[]) {
		snprintf(s, 149, COLOR"Shell: "CLOSE"%s", strrchr(getenv("SHELL"), '/') + 1);
}

void spacing(char m[]) {
		strcpy(m,"");
}

void get_term(char b[]) {
		snprintf(b, 149, COLOR"Terminal: "CLOSE"%s", getenv("TERM"));
}

void get_cpu(char r[]) {
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




		snprintf(r, 150, COLOR"CPU: "CLOSE"%s (%d) @ %.*f%s", cpu_model, num_cores, prec, freq, freq_unit);
    free(cpu_model);
}

void get_memory(char g[]) {
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

		snprintf( g, 149, COLOR"Memory: "CLOSE"%dMiB / %dMiB (%d%%)", used_memory, total_memory, percentage);

}

void get_colors(char d[]) {
    char *s = d;

    for(int i = 0; i < 8; i++) {
        sprintf(s, "\e[4%dm   ", i);
        s += 8;
    }
    snprintf(s, 5, "\e[0m");
}

void get_colors2(char x[]) {
		char *s = x;
    for(int i = 8; i < 16; i++) {
        sprintf(s, "\e[48;5;%dm   ", i);
        s += 12 + (i >= 10 ? 1 : 0);
    }
    snprintf(s, 5, "\e[0m");
}
void get_packages(char p[]) {
    int num_packages = 0;
    DIR * dirp;
    struct dirent *entry;

    dirp = opendir(PACDIR);

    if(dirp == NULL) {
		printf("dir doesn't exist");
    }

    while((entry = readdir(dirp)) != NULL) {
        if(entry->d_type == DT_DIR) num_packages++;
    }
    num_packages -= 2; // accounting for . and ..

    closedir(dirp);

    snprintf(p, 150, COLOR"Packages: "CLOSE"%d", num_packages);
}
int main() {
		uname(&u);
		sysinfo(&sys);
		hname(info[0], info[1]);
		order();

		for(int j = 0; j < ROWS; j++) {
				printf(COLOR "%s" CLOSE , logo[j]);
				printf("%s\n", info[j]);
		}
		printf("\n");
		return 0;
}
