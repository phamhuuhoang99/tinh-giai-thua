#include<stdio.h>

#include<string.h>

#define max 100

char TuDaiNhat(char s[]) {

            int i;

            int maxx=0, maxi=0;

            int len=strlen(s);

            if(s[0]==' ') {

                        for(i=0; i<len-1; i++) {

                                    if((s[i]==' ') && (s[i+1]!=' ')) {

                                                int j=i+1;

                                                int dem=0;

                                                while((s[j]!=' ') && (s[j]!='\0')) {

                                                            dem++;

                                                            j++;

                                                }

                                                if(dem>maxx) {

                                                            maxx=dem;

                                                            maxi=i+1;

                                                }

                                                i=j-1;

                                    }

                        }

            } else {

                        i=0;

                        int dem=0;

                        while((s[i]!=' ') && (s[i]!='\0')) {

                                    dem++;

                                    i++;

                        }

                        if(dem>maxx) {

                                    maxx=dem;

                                    maxi=0;

                        }

                        for(i=maxx-1; i<len-1; i++) {

                                    if((s[i]==' ') && (s[i+1]!=' ')) {

                                                int j=i+1;

                                                int de=0;

                                                while((s[j]!=' ') && (s[j]!='\0')) {

                                                            de++;

                                                            j++;

                                                }

                                                if(de>maxx) {

                                                            maxx=de;

                                                            maxi=i+1;

                                                }

                                                i=j-1;

                                    }

                        }

            }

            int k;

            for(k=maxi; k<(maxi+maxx); k++) {

                        printf("%c",s[k]);

            }

}

int main() {

            char s[max];

            printf("Nhap xau: ");

            gets(s);

 

            printf("Tu dai nhat trong chuoi:\n");

            TuDaiNhat(s);

}

 
