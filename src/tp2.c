#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>


/*
   static enum long_options{help, output-fromat, output-filename, show-languages, 
   show-capital, show-borders, show-flag, country, region
   } 
   static struct option long_opts[] =
   {
   {"help",     no_argument,       0, 'a'},
   {"output-format",  required_argument,       0, 'b'},
   {"output-filename",  required_argument, 0, 'c'},
   {"show-languages",   no_argument,  0, 'd'},
   {"show-capital",   no_argument,, 0, 'e'},
   {"show-borders",    no_argument, 0, 'f'},
   {"show-flag",    no_argument, 0, 'g'},
   {"country",    required_argument, 0, 'h'},
   {"region",    required_argument, 0, 'i'},
   {0, 0, 0, 0}
   };*/

void getopts(int argc, char *argv[]);
void help();
bool readArgs();

int main(int argc, char *argv[]){
    /*
       char format[3];
       char fileName[55];
       bool languages = false;
       bool capital = false;
       bool borders = false;
       bool flag = false;
       char country[3];
       char region[10];
       int option;    
       while ((option = getopt_long(argc, argv, "help", longopts, &index)) != -1) {

       switch (option){

       case 1:
       help();

       }



       }
       */ getopts(argc,argv);
    return 0;
}
/*
   bool readArgs(char *argv[]){



   while(++(*argv)){

   printf("%c\n", *argv[]);


   if (argv[] == "help\0"){
   help();

   } else if (argv[] == "output-fromat"){

   break;
   } else if(argv[] == "output-filename"){

   break;
   } else if(argv[] == "show-languages"){

   break;
   } else if(argv[] == "show-capital"){

   break;
   } else if (argv[] == "show-borders"){

   break;
   } else if (argv[] == "show-flag"){

   break;
   }else if (argv[] == "country"){

   break;
   } else if (argv[] == "region"){

   break;
   }



   }

   return true;

   }

*/

//Imprime a l'ecran le message d'aide et termine le programme.
void getopts(int argc, char *argv[]){

    int option;
    int index;
    static struct option long_opts[] =
    {
        {"help",     no_argument,       0, 'a'},
        {"output-format",  required_argument,       0, 'b'},
        {"output-filename",  required_argument, 0, 'c'},
        {"show-languages",   no_argument,  0, 'd'},
        {"show-capital",   no_argument, 0, 'e'},
        {"show-borders",    no_argument, 0, 'f'},
        {"show-flag",    no_argument, 0, 'g'},
        {"country",    required_argument, 0, 'h'},
        {"region",    required_argument, 0, 'i'},
        {0, 0, 0, 0}
    };
    printf("crap\n");
    while ((option = getopt_long(argc, argv, "ab:c:defgh:i:", long_opts, &index)) != -1) {
        printf("crapwhile\n%c\n", option);   
        switch (option){

            case 'a':
                help();
                break;
        }


    }
}
void help(){

    printf("helpmsg\n");

}



