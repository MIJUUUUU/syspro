#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>

void printStat(char *, char *, struct stat *, char *);
char type(mode_t);
char *perm(mode_t);

int main(int argc, char **argv)
{
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ + 1];

    char *options = "";

    if (argc > 1 && argv[1][0] == '-')
    {
        options = argv[1] + 1;
        dir = (argc == 2) ? "." : argv[2];
    }
    else
    {
        dir = (argc == 1) ? "." : argv[1];
    }

    if ((dp = opendir(dir)) == NULL)
    {
        perror(dir);
        exit(1);
    }

    while ((d = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", dir, d->d_name);
        if (lstat(path, &st) < 0)
        {
            perror(path);
            continue;
        }

        printStat(path, d->d_name, &st, options);
    }

    closedir(dp);
    exit(0);
}

void printStat(char *pathname, char *file, struct stat *st, char *options)
{
    if (strchr(options, 'p') && S_ISDIR(st->st_mode))
    {
        printf("%s/", file);
    }
    else
    {
        printf("%s", file);
    }

    if (strchr(options, 'i'))
    {
        printf(" %5ld", (long)st->st_ino);
    }

    if (strchr(options, 'Q'))
    {
        printf(" \"%s\"", file);
    }

    printf(" %c%s", type(st->st_mode), perm(st->st_mode));
    printf(" %3ld", (long)st->st_nlink);
    printf(" %s %s", getpwuid(st->st_uid) ? getpwuid(st->st_uid)->pw_name : "unknown",
           getgrgid(st->st_gid) ? getgrgid(st->st_gid)->gr_name : "unknown");
    printf(" %9ld", (long)st->st_size);
    printf(" %.12s", ctime(&st->st_mtime) + 4);
    printf("\n");
}

char type(mode_t mode)
{
    if (S_ISREG(mode))
        return '-';
    if (S_ISDIR(mode))
        return 'd';
    if (S_ISCHR(mode))
        return 'c';
    if (S_ISBLK(mode))
        return 'b';
    if (S_ISLNK(mode))
        return 'l';
    if (S_ISFIFO(mode))
        return 'p';
    if (S_ISSOCK(mode))
        return 's';

    return '?';
}

char *perm(mode_t mode)
{
    static char perms[10];
    strcpy(perms, "---------");

    for (int i = 0; i < 3; i++)
    {
        if (mode & (S_IRUSR >> i * 3))
            perms[i * 3] = 'r';
        if (mode & (S_IWUSR >> i * 3))
            perms[i * 3 + 1] = 'w';
        if (mode & (S_IXUSR >> i * 3))
            perms[i * 3 + 2] = 'x';
    }
    return (perms);
}

