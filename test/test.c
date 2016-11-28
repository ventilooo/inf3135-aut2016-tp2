#include "test.h"

int main() {

    CU_pSuite pSuite;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    
    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite_country", suite_country,suite_sortie);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

int suite_country(void) {

    //init
    json_t *objetJson ;
    objetJson = json_load_file("./data/countries/countries.json", 0, NULL);
    int toto = json_array_size(objetJson);

    if (getIndexPays(objetJson, "aruba", toto) == 0) {
        return -1;
    } else {
        return 0;
    }

    /*if (strcmp(getCapitales(objetJson, 0),"Oranjestad") != 0) {
        return -1;
    }else{
        return 0;
    }*/
}

int suite_sortie(void) {
    //init
    json_t *objetJson ;
    objetJson = json_load_file("./data/countries/countries.json", 0, NULL);
    int nbCountry = json_array_size(objetJson);
    return 0;
}
