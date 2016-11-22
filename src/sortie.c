#include "tp2.h"

FILE * initGraphFile(char * filename);
void closeGraphFile(FILE fGraph);
void addPays(FILE fGraph, int pays);


FILE * initGraphFile(char * filename){

    FILE *fGraph;
    fGraph = fopen("../bin/%s.dot", "w", filename);
    fprintf(fGraph, "graph {");
    return fGraph;

}
void closeGraphFile(FILE fGraph){

    fprintf(fGraph, "}");
    fclose(fGraph);
}
void addPays(FILE fGraph, int pays){

    fprintf(fGraph, "%s [", pays);
    fprintf(fGraph, "shape = none,");
    fprintf(fGraph, " label = <<table border="0" cellspacing="0">");
    fprintf(fGraph, " <tr><td align=\"center\" border=\"1\" fixedsize=\"true\" width=\"200\" height=\"100\">
            <img src=\"%s.png\" scale=\"true\"/></td></tr>",getPays() );
    fprintf(fGraph," <tr><td align=\"left\" border=\"1\"><b>Name</b>: %s</td></tr>", getPays(pays));
    fprintf(fGraph, "<tr><td align=\"left\" border=\"1\"><b>Code</b>: %s</td></tr>", pays);
    fprintf(fGraph, "<tr><td align=\"left\" border=\"1\"><b>Capital</b>: %s</td></tr>", getCapital());
 languages(fGraph, pays, languages);
    fprintf(fGraph, "<tr><td align=\"left\" border="1"><b>Borders</b>: %s</td></tr>", getBorders());
    fprintf(fGraph, "  </table>>");
    fprintf(fGraph, " ];");

}

void languages(FILE fGraph, int pays, bool languages){
    if(languages){
        fprintf(fGraph, "<tr><td align=\"left\" border=\"1\"><b>Language</b>: %s</td></tr>", getLanguage(pays));
    }
}

void capital(FILE fGraph, int pays, bool capital){
    if(capital){
        fprintf(fGraph, "<tr><td align=\"left\" border=\"1\"><b>Capital</b>: %s</td></tr>", getCapital(pays));
    }
}

void borders(FILE fGraph, int pays, bool borders){
    if(borders){
    
    fprintf(fGraph, "<tr><td align=\"left\" border="1"><b>Borders</b>: %s</td></tr>", getBorders());
}
}
