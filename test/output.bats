#!/usr/bin/env bats

@test "usage" {
    run ./bin/tp2 --help
    [ "${lines[0]}" = "Usage: bin/tp2 [--help] [--output-format FORMAT] [--output-filename FILENAME]" ]
    [ "${lines[1]}" = " [--show-languages] [--show-capital] [--show-borders] [--show-flag]" ]
    [ "${lines[2]}" = " [--country COUNTRY] [--region REGION]" ]
    [ "${lines[3]}" = "Displays informations about countries." ]
    [ "${lines[4]}" = "Optional arguments:" ]
    [ "${lines[5]}" = "    --help Show                this help message and exit." ]
    [ "${lines[6]}" = "    --output-format FORMAT     Selects the ouput format (either \"text\", \"dot\" or \"png\")." ]
    [ "${lines[7]}" = "                               The \"dot\" format is the one recognized by Graphviz." ]
    [ "${lines[8]}" = "                               The default format is \"text\"." ]
    [ "${lines[9]}" = "    --output-filename FILENAME The name of the output filename. This argument is" ]
    [ "${lines[10]}" = "                               mandatory for the \"png\" format. For the \"text\" and \"dot\"" ]
    [ "${lines[11]}" = "                               format, the result is printed on stdout if no output" ]
    [ "${lines[12]}" = "                               filename is given." ]
    [ "${lines[13]}" = "    --show-languages           The official languages of each country are displayed." ]
    [ "${lines[14]}" = "    --show-capital             The capital of each country is displayed." ]
    [ "${lines[15]}" = "    --show-borders             The borders of each country is displayed." ]
    [ "${lines[16]}" = "    --show-flag                The flag of each country is displayed." ]
    [ "${lines[17]}" = "                               (only for \"dot\" and \"png\" format)." ]
    [ "${lines[18]}" = "    --country COUNTRY          The country code (e.g \"can\", \"usa\") to ble displayed." ]
    [ "${lines[19]}" = "    --region REGION            The region of the countries to displayed." ]
    [ "${lines[20]}" = "                               The supported regions are \"africa\", \"americas\"," ]
    [ "${lines[21]}" = "                               \"asia\", \"europe\" and \"oceania\"." ]
}

@test "Test Canada long" {
    run ./bin/tp2 --country can --show-languages --show-capital --show-borders
    [ "${lines[0]}" = "Name: Canada" ]
    [ "${lines[1]}" = "Code: CAN" ]
    [ "${lines[2]}" = "Capital: Ottawa" ]
    [ "${lines[3]}" = "Languages: English, French" ]
    [ "${lines[4]}" = "Borders: USA" ]
}

@test "Test Canada short" {
    run ./bin/tp2 --country can
    [ "${lines[0]}" = "Name: Canada" ]
    [ "${lines[1]}" = "Code: CAN" ]
}

@test "Test dot output" {
    run bin/tp2 --country can --show-languages --show-capital --show-borders --show-flag --output-format dot 
    [ "${lines[0]}" = "graph {" ]
    [ "${lines[1]}" = "can [" ]
    [ "${lines[2]}" = "shape = none," ]
    [ "${lines[3]}" = "label = <<table border="0" cellspacing="0">" ]
    [ "${lines[4]}" = "<tr><td align="center" border="1" fixedsize="true" width="200" height="100"><img src="can.png" scale="true"/></td></tr>" ]
    [ "${lines[5]}" = "<tr><td align="left" border="1"><b>Name</b>: Canada</td></tr>" ]
    [ "${lines[6]}" = "<tr><td align="left" border="1"><b>Code</b>: CAN</td></tr>" ]
    [ "${lines[7]}" = "<tr><td align="left" border="1"><b>Capital</b>: Ottawa</td></tr>" ]
    [ "${lines[8]}" = "<tr><td align="left" border="1"><b>Language</b>: French, English</td></tr>" ]
    [ "${lines[9]}" = "<tr><td align="left" border="1"><b>Borders</b>: USA</td></tr>" ]
    [ "${lines[10]}" = "</table>>" ]
    [ "${lines[11]}" = "];" ]
    [ "${lines[12]}" = "}" ]
}
