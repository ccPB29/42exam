// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>



#include <unistd.h>
#include <stdio.h>

int len(char *str) {
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void	cmb(char *s1, char *s2, char *str){
	
	int	i =	0;

	while(s1[i]){
		str[i] = s1[i];
		i++;
	}
	while(s2[i-len(s1)]){
		str[i] = s2[i-len(s1)];
		i++;
	}
	str[i] = '\0';

}

void smlwr(char *str) {
    int i;
    int j;
    int s;
    int l = len(str);

    i = 0;
    while (i < l) {
        s = 0;
        j = 0;
        while (j < i) {
            if (str[i] == str[j]) {
                s = 1;
            }
            j++;
        }
        if (s == 0) {
            write(1, &str[i], 1);
        }
        i++;
    }
}

int main(int argc, char *argv[]) {
    char   *s1 = argv[1];
    char   *s2 = argv[2];
	char	s[len(s1)+len(s2)+1];
    
    if(argc != 3){
        write(1, "\n", 1);
        return(0);
    }
    cmb(s1, s2, s);
    smlwr(s);
    write(1, "\n", 1);
    return 0;
}