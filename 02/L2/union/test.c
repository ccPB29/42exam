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