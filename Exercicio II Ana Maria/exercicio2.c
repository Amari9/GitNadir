#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define pkgs_log "logs.zlf"
#define STR_MAX 1024


 int main(){
    FILE *fp = fopen(pkgs_log, "w+");
    int parse(FILE* fp, FILE* num_do_pkg, FILE* lat, FILE* longt, FILE* alt, FILE* num_de_sat, FILE* pres, FILE* temp){
        char num_do_pacote[STR_MAX], latitude[STR_MAX], longitude[STR_MAX], altitude[STR_MAX], num_de_satelites[STR_MAX], pressao[STR_MAX], temperatura[  STR_MAX];
        fscanf(fp,"%s;%s;%s;%s:%s;%s;%s", num_do_pacote, latitude, longitude, altitude, num_de_satelites, pressao, temperatura);
        fprintf(num_do_pkg, ";%s" num_do_pacote, lat, ";%s" latitude, longt, ";%s" longitude, alt, ";%s" altitude, num_de_sat, ";%s" num_de_satelites, pres, ";%s" pressao, temp, ";%s" temperatura);
        return 0;
    }
return 0;
 }


