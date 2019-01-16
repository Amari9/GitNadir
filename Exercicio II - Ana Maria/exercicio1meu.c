#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define max_pkg_len 1024
#define sent_pkgs_log "logs_sent.zlf"
#define received_pkgs_log "logs_received.zlf"

typedef struct pacote{
    int num;
    char message[max_pkg_len];
}Package;

int pkg_num = 0;
int countLogs (char *);
Package readPackage();
void formatPackage(Package, char *);

int main(){
    FILE *fp;
    Package pkg;
    int writeSuccesful, mode = 0;
    char formatedPkg[max_pkg_len];

    pkg_num = countLogs(sent_pkgs_log);
    printf("Modo de operacao\n\t [0]Enviar mensagem\n\t [1]Receber Mensagem\n\t>");

    scanf("%d", &mode);
    while(getchar() != '\n');

    if(mode){
        //Enviando
        while(1){
            char *line = NULL;
            size_t size;

            system("clear");
            printf("Mensagem:\n");

            getline(&line, &size, stdin);
            printf("%s", line);

            strcpy(pkg.message, line);
            pkg.num = pkg_num++;

            writeSuccesful = appendPackageInFile(pkg, sent_pkgs_log);
            printf("%s", writeSuccesful ? "Mensagem enviada." : "Mensagem nao enviada.");
        }
    }else{
        //Recebendo
        int last_line_count = count_logs(received_pkgs_log);
        int last_diff = 0;
        int actual_line_count = count_logs(received_pkgs_log);

        while(1){
            system("clear");
            if(actual_line_count > last_line_count){
                last_diff = actual_line_count - last_line_count;
                last_line_count = actual_line_count;
            }
            if(last_diff){
                FILE *received = fopen(received_pkgs_log, "r");
                char ch;
                int lines = 0;
                if(received == NULL) continue;
                printf("Novas mensagens [%d]:\n", last_diff);
                while(!feof(received)){
                    ch = fgetc(received);
                    if(ch == '\n') lines++;

                    if(lines > last_line_count - last_diff - 1){
                        printf("%c", ch);
                    }
                }
            }else{
                printf("Sem ultimas mensagens.\n");
                }
            sleep(1);
        }
    }
    return 0;
}

int countLogs(char * filename){
    int lines;
    char ch;

    FILE *file;
    file = fopen(filename, "r");

    if(file == NULL) return 0;

    while(!feof(file)){
        ch = fgetc(file);
        if(ch == '\n') lines ++;
    }
    fclose(file);
    return lines;
}

void formatPackage(Package pkg, char * buffer){
    sprintf(buffer, "%d;%s\n", pkg.num, pkg.message);
}

 int appendPackageInFile(Package pkg, char *filename){
    FILE *f;
    f = fopen(filename, "a");

    if(f == NULL)return 0;

    char buffer[max_pkg_len];
    formatPackage(pkg, buffer);
    printf("%s", buffer);
    fflush(stdout);

    fputs(buffer, f);

    fclose(f);

    return 1;
 }
