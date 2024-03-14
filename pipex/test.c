#include "pipex_bonus.h"

size_t  ft_strlen_delimiter(const char *str, char c)
{
        size_t  i;

        i = 0;
        while (str[i] && str[i] != c)
                i++;
        return (i);
}

int     ft_check_path(char *cmd)
{
        int     i;

        i = 0;
        while (cmd[i] == ' ')
                i++;
        while (cmd[i] && cmd[i] != ' ')
                if (cmd[i++] == '/')
                        return (0);
        return (1);
}

char    *ft_get_cmd(char *cmd)
{
    int i;
    int j;
    char *new_cmd;

    while (*cmd == ' ')
        cmd++;
    if (ft_check_path(cmd))
        return (ft_strdup(cmd));
    while (cmd[i] && cmd[i] != ' ')
        if (cmd[i++] == '/')
            j = i;
    if ((ft_strlen_delimiter(cmd + j, ' ') + 1) == 1)
        return (NULL);
    new_cmd = malloc(ft_strlen_delimiter(cmd + j, ' ') + 1);
    if (!new_cmd)
        return (NULL);
    i = 0;
    while (cmd[j] && cmd[j] != ' ')
        new_cmd[i++] = cmd[j++];
    new_cmd[i] = '\0';
    return (new_cmd);
}

int main()
{
    char *cmd = "         /bin/ls/sadf/asdf/hello/";
    char *res = ft_get_cmd(cmd);
    if (!res)
        return (0);
    printf("%s \n", res);
    free(res);
}
