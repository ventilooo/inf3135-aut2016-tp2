#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include <unistd.h>
#include "../src/country.h"
#include "../src/sortie.h"

int suite_init(void);

int suite_clean(void);

void suite_country(void);

void suite_sortie(void);

int doesFileExist(const char *filename);
