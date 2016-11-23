#include "tp2.h"
#include "country.h"

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
void addPays(FILE fGraph, int indexPays){

    fprintf(fGraph, "%s [", pays);
    fprintf(fGraph, "shape = none,");
    fprintf(fGraph, " label = <<table border="0" cellspacing="0">");
    fprintf(fGraph, " <tr><td align=\"center\" border=\"1\" fixedsize=\"true\" width=\"200\" height=\"100\">
            <img src=\"%s.png\" scale=\"true\"/></td></tr>", getCodePays(objetJson, indexPays));
    fprintf(fGraph," <tr><td align=\"left\" border=\"1\"><b>Name</b>: %s</td></tr>", getNomPays(objetJson, indexPays));
    fprintf(fGraph, "<tr><td align=\"left\" border=\"1\"><b>Code</b>: %s</td></tr>", getCodePays(objetJson, indexPays));
    capitalOut(objetJson, indexPays, capital);
    languagesOut(fGraph, indexPays, languages);
    BordersOut(fGraph, indexPays, borders);
    fprintf(fGraph, "  </table>>");
    fprintf(fGraph, " ];");

}

void languagesOut(json_t *objetJson, FILE fGraph, int indexPays, bool languages){
    char strLangues[MAXLENGTHLANGUES];
    if(languages){
        fprintf(fGraph, "<tr><td align=\"left\" border=\"1\"><b>Language</b>: %s</td></tr>", getLanguage(objetJson, indexPays, strLangues));
    }
}

void capitalOut(Fjson_t *objetJson, FILE fGraph, int indexPays, bool capital){
    if(capital){
        fprintf(fGraph, "<tr><td align=\"left\" border=\"1\"><b>Capital</b>: %s</td></tr>", getCapital(objetJson, indexPays));
    }
}

void bordersOut(FILE fGraph, int indexPays, bool borders){
    char strBorders[MAXLENGTHBORDERS];
    if(borders){
        fprintf(fGraph, "<tr><td align=\"left\" border="1"><b>Borders</b>: %s</td></tr>", getBorders(objetJson, indexPays, strBorders));
    }
}

void frontieresOut(int indexPays){


}
