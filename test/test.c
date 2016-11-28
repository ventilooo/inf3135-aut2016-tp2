#include "test.h"

int main() {

    CU_pSuite pSuite;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();
    
    /* add a suite to the registry */
    pSuite = CU_add_suite("Suite de Test", suite_init,suite_clean);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "Country", suite_country)) ||
        (NULL == CU_add_test(pSuite, "Sortie", suite_sortie)))
        {
            CU_cleanup_registry();
            return CU_get_error();
        }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

int suite_init(void){
    return 0;
}

int suite_clean(void){
    return 0;
}

void suite_country(void) {

    //init
    json_t *objetJson;
    objetJson = json_load_file("./data/countries/countries.json", 0, NULL);
    int nbTotal = json_array_size(objetJson);

    const char *test_name_capital = "Oranjestad";
    const char *test_name_country = "Afghanistan";
    const char *test_code = "ANG";

    CU_ASSERT(getIndexPays(objetJson, "abw", nbTotal) == 0);
    CU_ASSERT(strcmp(getNomPays(objetJson, 0), test_name_country) != 0);
    CU_ASSERT(strcmp(getCapitale(objetJson, 1), test_name_capital) != 0);
    CU_ASSERT(strcmp(getCode(objetJson,2), test_code) != 0);
}

void suite_sortie(void) {
    CU_ASSERT(0==0);
}
