#include "stdio.h"
#include "stdlib.h"
#include "string.h"
 



int 
main(int argc ,char *arg[])
{
	char *x[] = {"strcpy(", "stcat(","sprintf(", "gets(","getpw("};
	char *y[] = {"strlcpy() veya strncpy()","strlcat() veya strncat()","snprintf()","fgets()","getpwuid()"};
	
	if (argc == 3)
	{
		if (!strcmp(arg[1], "-s"))
		{
			FILE *fileptr = fopen(arg[2], "r");
			if (fileptr == NULL){
				printf("Dosya Açılamadı.\n");
				exit(1);
			}
			else
			{
				int sayac = 0;
				char *buffer = NULL;
  				size_t size_buffer = 0;
				size_t size = getline(&buffer, &size_buffer, fileptr);
				
				while(size >=0)
				{
					sayac++;
					for (int j =0; j<5;j++)
					{
						if(strstr(buffer, x[j]))
						{
							printf("Satir %d: %s) kullanılmış\n",sayac,x[j]);	
							break;
						}	
					} 

					size = getline(&buffer, &size_buffer, fileptr);
				}

				fclose(fileptr);
			}			
		}
		else if(!strcmp(arg[1], "-r"))
		{
			FILE *fileptr;
                        fileptr = fopen(arg[2], "r");
                        if (fileptr == NULL)
						{
                                printf("Dosya Açılamadı.\n");
                                exit(1);
                        }
						else
						{
								int sayac = 0;
                                char *buffer = NULL;
                                size_t size_buffer = 0;
                                size_t size = getline(&buffer, &size_buffer, fileptr);
                                
                                while(size >=0)
								{
                                        sayac++;
                                        for (int i =0; i<5;i++)
										{
                                                if(strstr(buffer, x[i]))
												{
                                                        printf("Satir %d: %s) kullanılmış, yerine %s kullanmalısınız.\n",sayac,x[i],y[i]);
                                                        break;
                                                }
                                        }

                                        size = getline(&buffer, &size_buffer, fileptr);
                                }

                                fclose(fileptr);
                        }
	
		}
	}
	else
	{
		printf("Kullanim:./soru2 parametre(-r,-s) dosya_adi\n");
		exit(1);
	}


	return 0;
}
