#include<stdio.h>
#include<direct.h>  //_mkdir()
#include<stdlib.h>

void createFile(const char *path, const char *content)
{
    FILE *fptr;

    fptr = fopen(path,"w");

    if(fptr == NULL)
    {
        printf("Error: Could not create/open the file\n");
        exit(1);    //exit with error code
    }
    
    printf("File created successfully\n");

    fprintf(fptr,content);

    fclose(fptr);
}

int main()
{
    if((_mkdir(".som")) == 0)
    {
        _mkdir(".som/objects");
        _mkdir(".som/objects/commits");
        _mkdir(".som/objects/blobs");
        _mkdir(".som/objects/trees");
        _mkdir(".som/refs");
        _mkdir(".som/refs/heads");
        _mkdir(".som/refs/tags");

        createFile(".som/HEAD", "ref: refs/heads/master\n");
        createFile(".som/config","username=YourName\nemail=your@email.com\n");
        createFile(".som/index","");

        createFile(".som/refs/heads/master.txt","");

        printf("Initialized empty .SOM repository\n");
    }
    else
    {
        printf("Already initiazed with SOM repository\n");
    }

    return 0;
}