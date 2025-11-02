/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguthman <eguthman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 00:33:17 by boletusedul       #+#    #+#             */
/*   Updated: 2024/11/15 14:24:13 by eguthman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <ctype.h>
# include <stdio.h>
# include <stddef.h>

// Pour ft_strmapi
char increment(unsigned int i, char c)
{
    (void)i;
    return (c + 1);
}

// Pour ft_striteri
void increment_char(unsigned int i, char *c)
{
    (void)i;
    *c = *c + 1;
}

// strlcpy de la libc pour la comparaison dans ft_strlcpy
size_t	strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len = 0;
	size_t	i = 0;

	while (src[src_len] != '\0')
		src_len++;

	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		if (i < size)
			dst[i] = '\0';
	}
	return src_len;
}
// strlcat de la libc pour la comparaison dans ft_strlcat
size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len = 0;
	size_t	src_len = 0;
	size_t	i;

	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;

	while (src[src_len] != '\0')
		src_len++;

	if (dst_len == size)
		return (size + src_len);

	i = 0;
	while (src[i] != '\0' && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}

	if (dst_len + i < size)
		dst[dst_len + i] = '\0';

	return (dst_len + src_len);
}

// Pour ft_lstiter
void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

// pour ft_lstmap.c
void	*add_one(void *content)
	{
	int	*new_content = malloc(sizeof(int));
	if (!new_content)
		return (NULL);
	*new_content = *(int *)content + 1;
		// (int *)content = on caste content en pointeur vers int
		// *(int *)content : le * dereference le ptr pour acceder a la valeur stockee a l'adr pointee
		return (new_content);
	}

// pour ft_lstclear & ft_lstmap.c
void	delete_content(void *content)
	{
		free(content);
	}

int main(void)
{	
	printf("\n\n\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
	printf("    PARTIE 1 - FONCTIONS DE LA LIBC\n");
	printf("/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n\n");

    printf("\n>>>>> ISALPHA : 1024 si que des alpha, 0 si autres chars\n");
    printf("FT_ISALPHA\n");
    printf("On envoie C : %d\n", ft_isalpha('C'));
    printf("On envoie a : %d\n", ft_isalpha('a'));
    printf("On envoie 2 : %d\n", ft_isalpha('2'));
    printf("On envoie / : %d\n", ft_isalpha('/'));
    printf("ISALPHA LIB C\n");
    printf("On envoie C : %d\n", isalpha('C'));
    printf("On envoie a : %d\n", isalpha('a'));
    printf("On envoie 2 : %d\n", isalpha('2'));
    printf("On envoie / : %d\n", isalpha('/'));
   
    printf("\n----------------------------------------------------------------\n");
    printf("\n>>>>> ISDIGIT : 2048 si chiffre, 0 si autre char\n");
    printf("FT_ISDIGIT\n");
    printf("On envoie 2 : %d\n", ft_isdigit('2'));
    printf("On envoie a : %d\n", ft_isdigit('a'));
    printf("On envoie / : %d\n", ft_isdigit('/'));
    printf("ISDIGIT LIB C\n");
    printf("On envoie 2 : %d\n", isdigit('2'));
    printf("On envoie a : %d\n", isdigit('a'));
    printf("On envoie / : %d\n", isdigit('/'));

    printf("\n----------------------------------------------------------------\n");
    printf("\n>>>>> ISALNUM : 8 si que des alphanums, 0 si autres chars\n");
    printf("FT_ISALNUM\n");
    printf("On envoie 1 : %d\n", ft_isalnum('1'));
    printf("On envoie a : %d\n", ft_isalnum('a'));
    printf("On envoie B : %d\n", ft_isalnum('B'));
    printf("On envoie / : %d\n", ft_isalnum('/'));
    printf("ISALNUM LIB C\n");
    printf("On envoie 1 : %d\n", isalnum('1'));
    printf("On envoie a : %d\n", isalnum('a'));
    printf("On envoie B : %d\n", isalnum('B'));
    printf("On envoie / : %d\n", isalnum('/'));

    printf("\n----------------------------------------------------------------\n");
    printf("\n>>>>> FT_ISASCII : 1 si ascii, 0 si autre char\n");
    int i1;
    i1 = -1;
    while(i1 < 129)
    {
        printf("On verifie %d | ft_isascii : %d | isascii : %d\n", i1, ft_isascii(i1), isascii(i1));
        i1++;
    }

   	printf("\n----------------------------------------------------------------\n");
    printf("\n>>>>> ISPRINT : 16384 si chiffre, 0 si autre char\n");
    int i2;
    i2 = 0;
    while(i2 < 129)
    {
        printf("On verifie %d | ft_isprint : %d | isprint : %d\n", i2, ft_isprint(i2), isprint(i2));
        i2++;
    }

    printf("\n----------------------------------------------------------------\n");
    printf("\n>>>>> FT_STRLEN : calcule la longueur d'une chaine sans le \\0 final\n");
    
    const char *s1 = "Quarante-deux $*";
    printf("FT_STRLEN\n");
	printf("La longueur de la chaine 'Quarante-deux $*' est de : %zu\n", ft_strlen(s1));
    printf("STRLEN LIB C\n");
    printf("La longueur de la chaine 'Quarante-deux $*' est de : %zu\n", strlen(s1));
		
    printf("\n----------------------------------------------------------------\n");
    printf("\n>>>>> MEMSET : remplir n premiers octets de la zone mémoire pointée par s avec la valeur de l'octet c\n");
    printf("FT_MEMSET\n");
    char string1[50] = "Voici une chaine test";
    printf("Avant ft_memset: %s\n", string1);
    ft_memset(string1, 'X', 5);
    printf("Après ft_memset (remplace 5 premiers par 'X'): %s\n", string1);
    ft_memset(string1, '/', sizeof(string1) - 1);
    printf("Après ft_memset (remplace tout par '/'): %s\n", string1);
    printf("MEMSET LIB C\n");
    char string2[50] = "Voici une chaine test";
    printf("Avant memset: %s\n", string2);
    memset(string2, 'X', 5);
    printf("Après memset (remplace 5 premiers par 'X'): %s\n", string2);
    memset(string2, '/', sizeof(string2) - 1);
    printf("Après memset (remplace tout par '/'): %s\n", string2);

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> BZERO : met à 0 (\\0) les n premiers octets du bloc pointé par s \n");
	size_t n = 4;
	unsigned char s2[32];
	size_t i = 0;
	while (i < n)
	{
		s2[i] = 42;
		i++;
	}
	printf("Avant :\n");
	i = 0;
	while (i < n)
	{
		printf("%d ", s2[i]);
		i++;
	}
	printf("\n");
	printf("Apres FT_BZERO\n");
	{
	ft_bzero(s2, n);
	i = 0;
	while (i < n)
	{
		printf("%d ", s2[i]);
		i++;
	}
	printf("\n");
	printf("Apres BZERO LIB C\n");
	bzero(s2, n);
	i = 0;
	while (i < n)
	{
		printf("%d ", s2[i]);
		i++;
	}
	}

	printf("\n----------------------------------------------------------------\n");
    printf("\n>>>>> FT_MEMCPY : copie n premiers octets de la zone mémoire pointée par src vers celle pointée par dest.\n");
	{
        char ft[50] = "abcdefghijklmnopqrstuvwxyz";
        char std_C[50] = "abcdefghijklmnopqrstuvwxyz";

        ft_memcpy(ft, ft + 15, 10);
        memcpy(std_C, std_C + 15, 10);

        printf("ft_memcpy: %s\n", ft);
        printf("memcpy:    %s\n", std_C);

        if (strcmp(ft, std_C) == 0)
            printf("=> les deux fonctions donnent le même résultat.\n");
        else
            printf("=> les deux fonctions ne donnent pas le même résultat.\n");
    }
   /*
   		printf("\nTest avec src et dest non valides => segfault\n");
        char *ft_dest = 0x0;
        char *std_C_dest = 0x0;
        const char *src = "Test";

        printf("Test ft_memcpy avec dest = NULL et n > 0\n");
        ft_memcpy(ft_dest, src, 7);

        printf("Test memcpy avec dest = NULL et n > 0\n");
        memcpy(std_C_dest, src, 7);
	
		printf("\nTest avec dest = NULL et size > 0 qui fait segfault\n");
        char *ft_dest = NULL;
        char *std_C_dest = NULL;
        const char *src = "Test";

        printf("Test ft_memcpy avec dest = NULL et n > 0\n");
        ft_memcpy(ft_dest, src, 5);

        printf("Test memcpy avec dest = NULL et n > 0\n");
        memcpy(std_C_dest, src, 5);
	
		printf("\nTest avec src = NULL et size > 0 qui fait segfault\n");
        char ft_dest[50] = "Elodie";
        char std_C_dest[50] = "Guthmann";
        char *src = NULL;

        printf("Test ft_memcpy avec src = NULL et n > 0\n");
        ft_memcpy(ft_dest, src, 5);

        printf("Test memcpy avec src = NULL et n > 0\n");
        memcpy(std_C_dest, src, 5);
	*/
	
	printf("\n----------------------------------------------------------------\n");
    printf("\n>>>>> MEMMOVE : copie n octets de la zone mémoire pointée par src vers celle pointée par dest\n");

	{
		char ft[50] = "abcdefghijklmnopqrstuvwxyz";
		char std_C[50] = "abcdefghijklmnopqrstuvwxyz";

		ft_memmove(ft, ft + 15, 10);
		memmove(std_C, std_C + 15, 10);

		printf("ft_memmove: %s\n", ft);
		printf("memmove:    %s\n", std_C);

		if (strcmp(ft, std_C) == 0)
			printf("=> les deux fonctions donnent le même résultat.\n");
		else
			printf("=> les deux fonctions ne donnent pas le meme resultat\n");
	}

	/* Test avec pointeurs non valides identiques
	{
  	printf("Test de ft_memmove avec (0x1, 0x1, 7):\n");
    ft_memmove((void *)0x1, (void *)0x1, 7);
    printf("ft_memmove terminé sans crash.\n");

    printf("Test de memmove avec (0x1, 0x1, 7):\n");
    memmove((void *)0x1, (void *)0x1, 7);
    printf("memmove terminé sans crash.\n");

    return 0;
	}
	*/

    /*
    printf("\nTest avec dest = NULL et size > 0 qui fait segfault\n");
    {
        char *ft_dest = NULL;
        char *std_C_dest = NULL;
        const char *src = "Test";

        ft_memmove(ft_dest, src, 5);

        memmove(std_C_dest, src, 5);

    }
   
    printf("\nTest avec src = NULL et size > 0 qui fait segfault\n");
    {
        char ft_dest[50] = "Elodie";
        char std_C_dest[50] = "Guthmann";
        char *src = NULL;

        ft_memmove(ft_dest, src, 5);

        memmove(std_C_dest, src, 5);

    }
	*/

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> STRLCPY : Copie jusqu'à size - 1 chars de la chaîne src vers dst, et termine toujours la chaîne de destination par un char nul (\\0)\n");
	{
		size_t i = 4;
		char source[] = "Elodie";
		char destination_ft[20] = "Guthmann";
		char destination_libc[20] = "Guthmann";
		size_t result_ft;
		size_t result_libc;

		printf("Chaîne source : %s\n", source);
		printf("Destination initiale : %s\n", destination_ft);
		printf("Nombre de chars à copier : %zu\n", i);
		
		result_ft = ft_strlcpy(destination_ft, source, i);
		printf("\nRésultat ft_strlcpy : %zu chars\n", result_ft);
		printf("Nouvelle destination (ft_strlcpy) : %s\n", destination_ft);
		
		result_libc = strlcpy(destination_libc, source, i);
		printf("\nRésultat strlcpy (libc) : %zu chars\n", result_libc);
		printf("Nouvelle destination (strlcpy) : %s\n", destination_libc);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_STRLCAT : ajoute la chaîne src à la fin de la chaîne dst, pour un total de size chars\n");
	{
		size_t size = 15;
		char src[] = "World";
		char dst_ft[20] = "Hello ";
		char dst_libc[20] = "Hello ";
		size_t result_ft;
		size_t result_libc;

		printf("Chaîne source : \"%s\"\n", src);
		printf("Destination initiale : \"%s\"\n", dst_ft);
		printf("Taille maximale du buffer (size) : %zu\n\n", size);

		result_ft = ft_strlcat(dst_ft, src, size);
		printf("Résultat ft_strlcat : %zu\n", result_ft);
		printf("Nouvelle destination (ft_strlcat) : \"%s\"\n\n", dst_ft);

		result_libc = strlcat(dst_libc, src, size);
		printf("Résultat strlcat (libc) : %zu\n", result_libc);
		printf("Nouvelle destination (strlcat) : \"%s\"\n", dst_libc);
	}

    printf("\n----------------------------------------------------------------\n");
    printf("\n>>>>> TOUPPER : convertit minuscules en majuscules\n");
    {
		printf("FT_TOUPPER\n");
		printf("On envoie A: %c\n", ft_toupper('A'));
		printf("On envoie b: %c\n", ft_toupper('b'));
		printf("On envoie 1: %c\n", ft_toupper('1'));
		printf("On envoie \\: %c\n", ft_toupper('\\'));
		printf("TOUPPER LIB C\n");
		printf("On emvoie A: %c\n", toupper('A'));
		printf("On envoie b: %c\n", toupper('b'));
		printf("On envoie 1: %c\n", toupper('1'));
		printf("On envoie \\: %c\n", toupper('\\'));
	}

    printf("\n----------------------------------------------------------------\n");
    printf("\n>>>>> TOLOWER : convertit majuscules en minuscules\n");
    {
		printf("FT_TOLOWER\n");
		printf("On envoie A: %c\n", ft_tolower('A'));
		printf("On envoie b: %c\n", ft_tolower('b'));
		printf("On envoie 1: %c\n", ft_tolower('1'));
		printf("On envoie \\: %c\n", ft_tolower('\\'));
		printf("TOLOWER LIB C\n");
		printf("On emvoie A: %c\n", tolower('A'));
		printf("On envoie b: %c\n", tolower('b'));
		printf("On envoie 1: %c\n", tolower('1'));
		printf("On envoie \\: %c\n", tolower('\\'));
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> STRCHR : Recherche la première occurrence du char c dans la chaîne de chars s\n");
	{
		char		*result_ft;
		char		*result_libc;
		const char	*s = "Hello world";
		int			c;

		c = 'l';
		result_ft = ft_strchr(s, c);
		result_libc = strchr(s, c);
		printf("Chaine dans laquelle on recherche le char '%c' : %s\n", c, s);
		if (result_ft)
			printf("Avec ft_strchr : '%c' trouve au pointeur: %s\n", c, result_ft);
		else
			printf("Char '%c' non trouve dans la chaine.\n", c);
		if (result_libc)
			printf("Avec strchr : '%c' trouve au pointeur : %s\n", c, result_libc);
		else
			printf("Char '%c' non trouve dans la chaine.\n", c);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_STRRCHR : recherche la dernière occurrence du char c dans la chaîne de chars s\n");
	{
		char		*result_ft;
		char		*result_libc;
		const char	*s = "Hello world";
		int			c;

		c = 'o';
		result_ft = ft_strrchr(s, c);
		result_libc = ft_strrchr(s, c);

		printf("Chaine dans laquelle on recherche le char '%c' : %s\n", c, s);

		if (result_ft)
			printf("Avec ft_strrchr : '%c' trouve au pointeur: %s\n", c, result_ft);
		else
			printf("Char '%c' non trouve dans la chaine.\n", c);
		if (result_libc)
			printf("Avec strrchr : '%c' trouve au pointeur: %s\n", c, result_libc);
		else
			printf("Char '%c' non trouve dans la chaine.\n", c);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> STRNCMP : compare jusqu'à n chars des chaînes de chars s1 et s2\n");
	{
		char	*s1;
		char	*s2;
		size_t	i;

		i = 4;
		printf("n = %zu\n", i);
		s1 = "elodie";
		s2 = "elodxe";
		printf ("s1 = %s\ns2 = %s\ndiff = %d\n\n", s1, s2, ft_strncmp(s1, s2, i));
		s1 = "elxdie";
		s2 = "elodie";
		printf ("s1 = %s\ns2 = %s\ndiff = %d\n\n", s1, s2, ft_strncmp(s1, s2, i));
		s1 = "Elod";
		s2 = "Elodie";
		printf ("s1 = %s\ns2 = %s\ndiff = %d\n\n", s1, s2, ft_strncmp(s1, s2, i));
		s1 = "Elodie";
		s2 = "Elp";
		printf ("s1 = %s\ns2 = %s\ndiff = %d\n\n", s1, s2, ft_strncmp(s1, s2, i));
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> MEMCHR : recherche la première occurrence d'un octet spécifié (c) dans les n premiers octets de la zone mémoire pointée par s\n");
	{
		char str[] = "Hello world";
		int c1 = 'o'; 
		size_t n = strlen(str); 
		
		printf("Chaine dans laquelle on cherche: %s\n", str);

		void *result1 = ft_memchr(str, c1, n);
		void *result2 = memchr(str, c1, n);


		if (result1 != NULL)
			printf("ft_memchr: Char '%c' en pos : %ld\n", c1, (char *)result1 - str);
		else
			printf("ft_memchr: Char '%c' non trouvé\n", c1);

		if (result2 != NULL)
			printf("memchr: Char '%c' en pos : %ld\n", c1, (char *)result2 - str);
		else
			printf("memchr: char '%c' non trouvé\n", c1);

		int c2 = 'z';  
		result1 = memchr(str, c2, n);
		result2 = ft_memchr(str, c2, n);
		printf("\nOn cherche '%c'\n", c2);
		if (result1 == NULL && result2 == NULL)
			printf("=> les 2 fonctions ont retourne NULL pour '%c'\n", c2);
		else
			printf("Erreur avec '%c'\n", c2);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> MEMCMP : compare n premiers octets de 2 zones mémoire pointées par s1 et s2\n");
	{
		char src1[] = "Hello tout le monde";
		char src2[] = "Hello world";
		int l;
		int result_ft_memcmp;
		int result_memcmp;

		l = 7;
		printf("On teste avec %d\n", l);
		printf("Source1: %s\n", src1);
		printf("Source2: %s\n", src2);
		result_ft_memcmp = ft_memcmp(src1, src2, l);
		printf("Résultat avec ft_memcmp: %d\n", result_ft_memcmp);
		result_memcmp = memcmp(src1, src2, l);
		printf("Résultat avec memcmp: %d\n", result_memcmp);
	}

 	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> STRNSTR : recherche 1e occurrence de little dans big (recherche sur len 1ers chars de big\n");
	{
		const char	*big = "The needle is well hidden";
		const char	*little = "needle";
		size_t		len;
		char		*resultat;

		len = 15;
		resultat = ft_strnstr(big, little, len);
		printf("Big : %s\n", big);
		printf("Little : %s\n", little);
		if (resultat)
			printf("Chaine trouvee: %s\n", resultat);
		else
			printf("Chaine non trouvee dans les %zu premiers chars\n", len);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> ATOI : convertit chaine de chars en entier\n");
	{
		const char nptr[] = "    -123a567";
		printf("Chaine de depart (espaces avant le premier char): %s\n", nptr);
		printf("Apres FT_ATOI: %d\n", ft_atoi(nptr));
		printf("Apres ATOI LIB C: %d\n", atoi(nptr));
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> CALLOC : alloue mémoire pour tableau de nmemb éléments de taille size octets. Initialise tous les octets alloués à zéro.\n");
	{
		size_t	nmemb = 5;
		size_t	size = 4294967295;

		void	*result = ft_calloc(nmemb, size);
		if (result == NULL)
			printf("Overflow : ft_calloc renvoie NULL comme voulu.\n");
		else
		{
			printf("Pas d'overflow : ft_calloc ne renvoie pas NULL.\n");
			free(result);
		}
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> STRDUP : renvoie ptr sur nouvelle chaine de chars dupliquée depuis s.\n");
	{
		const char *s3 = "Learning how to use strdup";
		printf("Chaine a dupliquer : %s\n", s3);
		printf("Apres FT_STRDUP : %s\n", ft_strdup(s3));
		printf("Apres STRDUP LIB C : %s\n", strdup(s3));
		char *dup_str = ft_strdup(s3);
		free(dup_str);
	}

	printf("\n\n\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
	printf("    PARTIE 2 - FONCTIONS SUPPLEMENTAIRES\n");
	printf("/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n\n");

	printf("\n>>>>> FT_SUBSTR : extrait sous-chaîne d'une chaîne de chars donnée\n");
	{
		char			*initial_string;
		char			*resulting_substring;
		unsigned int	index_substring;
		size_t			length;

		initial_string = "Hello world";
		index_substring = 4;
		length = 3;
		resulting_substring = ft_substr(initial_string, index_substring, length);
		printf("Chaine initiale : %s\n", initial_string);
		printf("Index utilise : %d\n", index_substring);
		printf("Longueur : %zu\n", length);
		if (resulting_substring)
		{
			printf("Chaine extraite : %s\n", resulting_substring);
			free(resulting_substring);
		}
		else
			printf("L'extraction n'a pas pu se faire\n");
	}
   
	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_STRJOIN : concatène deux chaînes de chars (s1 et s2) en une seule nouvelle chaîne\n");
	{
		char			*string1;
		char			*string2;
		char			*resulting_string;

		string1 = "Elodie";
		string2 = "Guthmann";
		resulting_string = ft_strjoin(string1, string2);
		printf("Chaine 1 : %s\n", string1);
		printf("Chaine 2 : %s\n", string2);
		if (resulting_string)
		{
			printf("Nouvelle chaine : %s\n", resulting_string);
			free(resulting_string);
		}
		else
			printf("L'operation de concatenation a echoue.\n");
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_STRTRIM : supprime les chars spécifiés dans l'ensemble set du début et de la fin de la chaîne de chars s1\n");
	{
		char	*string1;
		char	*set;
		char	*trimmed_string;

		string1 = "xxxOh My Godxxx";
		set = "x";
		trimmed_string = ft_strtrim(string1, set);
		printf("Chaine a couper : %s\n", string1);
		printf("A retirer au debut et a la fin : %s\n", set);
		if (trimmed_string)
		{
			printf("Chaine coupee : %s\n", trimmed_string);
			free(trimmed_string);
		}
		else
			printf("Alloc memoire a echoue.\n");
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_SPLIT : découpe chaîne de chars en sous-chaînes avec un char délimiteur\n");
	{
		char	**result;
		char	c;
		char	*string;
		int		i;

		c = ' ';
		string = " Cette fonction etait la plus dure de libft !\n";
		printf("Chaine a decouper : %s", string);
		result = ft_split(string, c);
		i = 0;
		while (result[i])
		{
			printf("Sous-chaîne %d: %s\n", i, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_ITOA : convertit entier en  chaîne de chars\n");
	{
		char	*result;

		result = ft_itoa(0);
		printf("Avec 0 : %s\n", result);
		free(result);
		result = ft_itoa(1);
		printf("Avec 1 : %s\n", result);
		free(result);
		result = ft_itoa(-1);
		printf("Avec -1 : %s\n", result);
		free(result);
		result = ft_itoa(10);
		printf("Avec 10 : %s\n", result);
		free(result);
		result = ft_itoa(-10);
		printf("Avec -10 : = %s\n", result);
		free(result);
		result = ft_itoa(42);
		printf("Avec 42 : = %s\n", result);
		free(result);
		result = ft_itoa(-42);
		printf("Avec -42 : = %s\n", result);
		free(result);
		result = ft_itoa(-2147483648);
		printf("Avec -2147483648 : %s\n", result);
		free(result);
		result = ft_itoa(2147483647);
		printf("Avec 2147483647 : %s\n", result);
		free(result);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_STRMAPI : applique une fonction à chaque char d'une chaîne de chars\n");

	{
		const char	*original = "elodie";
		char		*result;

		result = ft_strmapi(original, increment);
		if (result == NULL)
		{
			printf("L'allocation de memoire a echoue!\n");
			return (1);
		}
		printf("Chaine initiale: %s\n", original);
		printf("apres fonction de transformation (+1 char)\n");
		printf("devient : %s\n", result);
		free(result);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_STRITERI : applique fonction à chaque char\n");
	{
		const char	original[] = "elodie";
		char		*result;

		result = malloc(strlen(original) + 1);
		if (result == NULL)
		{
			printf("Allocation memoire a echoue!\n");
			return (1);
		}
		strcpy(result, original);
		ft_striteri(result, increment_char);
		printf("Chaine initiale : %s\n", original);
		printf("apres fonction de transformation (+1 char)\n");
		printf("devient : %s\n", result);
		free(result);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> PUTCHAR_FD : écrit char sur fd specifique\n");
	{
		int fd;

		fd = 1;
		printf("On ecrit 'w' sur le fd 1.\nChar qu'on affiche :\n");
		ft_putchar_fd('W', fd);
		printf("\nOn a ecrit 'W' sur le fd %d\n", fd);
	}

   	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> PUTSTR_FD : écrit chaîne de chars sur fd specifique\n");
	{
		int	fd;

		fd = 1;
		printf("On ecrit...\n");
		ft_putstr_fd("Hello world", fd);
		printf("\n... sur le fd : %d\n", fd);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> PUTENDL_FD : écrit chaîne de chars sur fd specifique + \\n' à la fin\n");
	{
		int	fd;

		fd = 1;
		printf("On ecrit 'Hello world' + retour a la ligne sur fd 1.\n");
		ft_putendl_fd("Hello world", fd);
		printf("On a ecrit 'Hello world' sur le fd %d\n", fd);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> PUTNBR_FD\n");
	{
		int	fd;

		fd = 2;
		printf("On ecrit sur ce fd : %d\n", fd);
		ft_putnbr_fd(4, fd);
		printf("\nOn a ecrit '4' sur le fd : %d\n", fd);
		ft_putnbr_fd(0, fd);
		printf("\nOn a ecrit '0' sur le fd : %d\n", fd);
		ft_putnbr_fd(-9, fd);
		printf("\nOn a ecrit '-9' sur le fd : %d\n", fd);
		ft_putnbr_fd(9, fd);
		printf("\nOn a ecrit '9' sur le fd : %d\n", fd);
		ft_putnbr_fd(2147483647, fd);
		printf("\nOn a ecrit '2147483647' sur le fd : %d\n", fd);
		ft_putnbr_fd(-2147483647, fd);
		printf("\nOn a ecrit '-2147483647' sur le fd : %d\n", fd);
		ft_putnbr_fd(-2147483648, fd);
		printf("\nOn a ecrit '-2147483648' sur le fd : %d\n", fd);
	}

	printf("\n\n\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
   	printf("         PARTIE 3 - BONUS\n");
	printf("/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n\n");

	printf("\n>>>>> FT_LSTNEW\n");
	{
		char *str = "Hello world";

		t_list *node = ft_lstnew(str);

		if (node)
			printf("Nouveau noeud cree avec le contenu : %s\n", (char *)node->content);
		else
			printf("Echec de l'ajout d'un nouveau noeud\n");

		free(node);
	}
   
   	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_LSTADD_FRONT\n");
	{
		t_list node1;
		t_list node2;
		t_list node3;

		node1.content = "Noeud 1";
		node1.next = &node2;

		node2.content = "Noeud 2";
		node2.next = &node3;

		node3.content = "Noeud 3";
		node3.next = NULL;
		/*
		Ecriture alternative :
		t_list node3 = {"Noeud 3", NULL};
		t_list node2 = {"Noeud 2", &node3};
		t_list node1 = {"Noeud 1", &node2};
		*/

		t_list *my_list = &node1; // Commence par le premier nœud
		printf("Liste avant ajout de head:\n");
		t_list *node = my_list;
		while (node)
		{
			printf("Contenu: %s\n", (char *)node->content);
			node = node->next;
		}

		t_list new_node = {"[Ici le nouveau noeud]", NULL};
		ft_lstadd_front(&my_list, &new_node);

		printf("\nListe après ajout en tête:\n");
		node = my_list;
		while (node)
		{
			printf("Contenu: %s\n", (char *)node->content);
			node = node->next;
		}
	}
   	
	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_LSTSIZE (expecting 3)\n");
	{
		t_list	node1 = {"Noeud 1", NULL};
		t_list	node2 = {"Noeud 2", &node1};
		t_list	node3 = {"Noeud 3", &node2};
		t_list	*my_list;
		
		my_list = &node3;
		int	size = ft_lstsize(my_list);
		printf("Taille de la liste : %d noeuds\n", size);
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_LSTLAST (expecting 3)\n");
	{
		t_list node3 = {"Noeud 3", NULL};
		t_list node2 = {"Noeud 2", &node3};
		t_list node1 = {"Noeud 1", &node2};

		t_list *my_list = &node1;
		t_list *last = ft_lstlast(my_list);
		if (last)
			printf("Dernier élément : %s\n", (char *)last->content);
		else
			printf("La liste est vide.\n");
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_LSTADD_BACK\n");
	{
		t_list node1 = {"Element 1", NULL};
		t_list node2 = {"Element 2", &node1};
		t_list node3 = {"Element 3", &node2};

		t_list *my_list;
		my_list = &node3;
		printf("Liste avant ajout en tête:\n");
		t_list *node = my_list;
		while (node)
		{
			printf("Content: %s\n", (char *)node->content);
			node = node->next;
		}
		t_list new_node = {"[Nouveau noeud]", NULL};
		ft_lstadd_back(&my_list, &new_node);
		printf("\nListe après ajout en tête:\n");
		node = my_list;
		while (node)
		{
			printf("Content: %s\n", (char *)node->content);
			node = node->next;
		}
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_LSTDELONE\n");
	{
		char *content = malloc(sizeof(char) * 6);
		if (!content)
			{
				printf("Allocation memoire a echoue\n");
				return (1);
			}
	
		strcpy(content, "Hello");

		t_list *elem = malloc(sizeof(t_list));
		if (!elem)
		{
			free(content);
			return (1);
		}
		elem->content = content;
		elem->next = NULL;

		printf("Contenu avant suppression : %s\n", (char *)elem->content);

		ft_lstdelone(elem, free);
		
		elem = NULL;

		if (elem == NULL)
			printf("=> l'élément a été supprimé, ptr devenu NULL.\n");
		else
			printf("Echec de la suppression de l'element.\n");
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_LSTCLEAR\n");
	{
		t_list *head = malloc(sizeof(t_list));
		head->content = malloc(6);  
		strcpy(head->content, "Hello");

		head->next = malloc(sizeof(t_list));
		head->next->content = malloc(6);
		strcpy(head->next->content, "World");

		head->next->next = malloc(sizeof(t_list));
		head->next->next->content = malloc(3);
		strcpy(head->next->next->content, "42");

		head->next->next->next = NULL;

		ft_lstclear(&head, delete_content);

		if (head == NULL)
			printf("La liste est bien vide après ft_lstclear.\n");
		else
			printf("Erreur : la liste n'est pas vide.\n");
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_LSTITER\n");
	{
		t_list *head = malloc(sizeof(t_list));
		head->content = ft_strdup("Hello");

		head->next = malloc(sizeof(t_list));
		head->next->content = ft_strdup("World");

		head->next->next = malloc(sizeof(t_list));
		head->next->next->content = ft_strdup("42");

		head->next->next->next = NULL;

		printf("Contenu de la liste :\n");
		ft_lstiter(head, print_content);

		t_list *temp;
		while (head) {
			temp = head->next;
			free(head->content);
			free(head);
			head = temp;
		}
	}

	printf("\n----------------------------------------------------------------\n");
	printf("\n>>>>> FT_LSTMAP\n");
	{
		int		value = 5;
		t_list	*lst = ft_lstnew(&value);

		t_list	*new_lst = ft_lstmap(lst, add_one, delete_content);

		if (new_lst)
		{
			printf("Valeur initiale : %d\n", *(int *)lst->content);
			printf("Valeur après mapping : %d\n", *(int *)new_lst->content);
		}
		else
		{
			printf("Erreur, ft_lstmap a renvoye NULL\n");
		}

		ft_lstclear(&new_lst, delete_content);
	}
	
}

