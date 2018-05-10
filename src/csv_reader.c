#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Conditionals
const bool          IS_DEBUG            = true;

// Constants
const unsigned int  BUFFER_SIZE         = 2048;
const unsigned int  FIELD_SIZE          = 20;
const char          CSV_DELIMITERS[]    = ",";

// Globals
char**              CSV_HEADER_FIELDS;
unsigned int        CSV_NB_FIELDS;

void display_header()
{
    for(unsigned int i = 0; i < CSV_NB_FIELDS; i++)
    {
        printf("%d - %s\n", i, CSV_HEADER_FIELDS[i]);
    }
}

void read_csv_header(char * header_line)
{
    int     line_length = strlen(header_line);
    int     nb_fields   = 0;
    char*   string_ptr  = header_line;

    // Count the occurrences of delimiters
    while (NULL != string_ptr)
    {
        nb_fields++;
        string_ptr = strpbrk(string_ptr, CSV_DELIMITERS);
        if (NULL != string_ptr)
        {
            string_ptr++;
        }
    }

    // Globals allocation
    CSV_NB_FIELDS       = nb_fields;
    CSV_HEADER_FIELDS   = malloc( nb_fields * sizeof(char*) );

    char* token         = strtok(header_line, CSV_DELIMITERS);                  // strtok init.

    // Re-read the line to get the header of the columns
    for (unsigned int i = 0; i < nb_fields; i++)
    {
        CSV_HEADER_FIELDS[i] = malloc( FIELD_SIZE * sizeof(char) );             // alloc
        memset(CSV_HEADER_FIELDS[i], 0, FIELD_SIZE);                            // 0 init.
        strcpy(CSV_HEADER_FIELDS[i], token);                                    // copy field in the structure
        token = strtok(NULL, CSV_DELIMITERS);                                   // loop to get a new field label
    }

    if (IS_DEBUG) display_header();
}

void read_csv_file(const char * filename)
{
    FILE*   fp = fopen(filename, "r");
    char    buffer[BUFFER_SIZE];

    // Check if the file is really opened
    if (NULL == fp)
    {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        return;
    }

    // 1st row is a header with field descriptions
    fgets(buffer, BUFFER_SIZE, fp);
    read_csv_header(buffer);

    // Remaining rows are the entries
    while ( NULL != fgets(buffer, BUFFER_SIZE, fp) )
    {
        char*           token;
        unsigned int    i = 0;

        // strtok init.
        token = strtok(buffer, CSV_DELIMITERS);

        while (NULL != token)
        {
            if (IS_DEBUG) printf("Field %d is %s\n", i++, token);

            // ...
            // you can strcpy the `token` string in your data structures
            // ...

            token = strtok(NULL, CSV_DELIMITERS);
        }
    }

    fclose(fp);
}

void usage(const char * prog_name)
{
    printf("Usage is %s your_csv_file\n\n", prog_name);
}

int main(int argc, char * argv[])
{
    if (2 != argc)
    {
        usage(argv[0]);
        return 0;
    }

    read_csv_file(argv[1]);
    for(unsigned int i = 0; i < CSV_NB_FIELDS; i++)
    {
        free(CSV_HEADER_FIELDS[i]);
    }
    free(CSV_HEADER_FIELDS);

    return 0;
}
