#include "http_client.h"
#include <curl/curl.h>

int httpc_make_get_request(const char *url)
{
    if (!url) {
        return -1;
    }
    CURL *easy_handle = curl_easy_init();
    curl_easy_setopt(easy_handle, CURLOPT_URL, url);
    curl_easy_setopt(easy_handle, CURLOPT_VERBOSE, 1);
    curl_easy_perform(easy_handle);
    curl_easy_cleanup(easy_handle);
    return 0;
}
