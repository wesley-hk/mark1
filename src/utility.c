#include <stdlib.h>
#include "utility.h"
#include "logger.h"
#include "cJSON.h"

int json_test()
{
    MARK_DEBUG(DEBUG, "cJSON test start here");

    char *out;
    cJSON *json;

    FILE *fp = fopen("/home/wesley/code/mark1/mark1/test_files/test.json", "r");
    fseek(fp,0,SEEK_END);
	long len=ftell(fp);
	fseek(fp,0,SEEK_SET);
    char *data=(char*)malloc(len+1);
	fread(data,1,len,fp);
	// fclose(fp);

    json = cJSON_Parse(data);

    if (!json)
    {
        MARK_DEBUG(DEBUG, "Error before: [%s]\n", cJSON_GetErrorPtr());
    }
    else
    {
        out = cJSON_Print(json);
        cJSON_Delete(json);
        MARK_DEBUG(DEBUG, "%s\n", out);
        free(out);
    }

    fclose(fp);

    return 0;
}
