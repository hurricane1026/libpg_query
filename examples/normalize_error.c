#include <pg_query.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  PgQueryNormalizeResult result;

  pg_query_init();

  result = pg_query_normalize("SELECT $$$");

  if (result.error) {
    printf("error: %s at location %d (%s:%d)\n", result.error->message,
           result.error->cursorpos, result.error->filename, result.error->lineno);
    free(result.error->message);
    free(result.error->filename);
    free(result.error);
  } else {
    printf("%s\n", result.normalized_query);
  }

  free(result.normalized_query);

  return 0;
}