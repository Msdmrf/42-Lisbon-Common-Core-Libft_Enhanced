/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migusant <migusant@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:04:01 by migusant          #+#    #+#             */
/*   Updated: 2025/05/27 17:44:04 by migusant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 .main.c -L. -lft -o .main
// ./.main

#include "includes/libft.h"

// Helper function to print test headers
static void print_test_header(const char *component)
{
    ft_printf("\n%s", "==============================================\n");
    ft_printf("Testing %s functions\n", component);
    ft_printf("%s", "==============================================\n");
}

int main(void)
{
    print_test_header("LIBFT");
    
    // 1. ft_split
    ft_printf("\n1. Testing ft_split with 'Hello,World,42':\n");
    char **split_result = ft_split("Hello,World,42", ',');
    for (int i = 0; split_result[i]; i++)
    {
        ft_printf("   Split[%d]: %s\n", i, split_result[i]);
        free(split_result[i]);
    }
    free(split_result);

    // 2. ft_strtrim
    ft_printf("\n2. Testing ft_strtrim:\n");
    char *trim_result = ft_strtrim("   Hello World   ", " ");
    ft_printf("   Original: '   Hello World   '\n");
    ft_printf("   Trimmed: '%s'\n", trim_result);
    free(trim_result);

    // 3. ft_lstnew
    ft_printf("\n3. Testing ft_lstnew:\n");
    char *content = "Test Content";
    t_list *node = ft_lstnew(content);
    ft_printf("   Node content: %s\n", (char *)node->content);
    free(node);

    // 4. ft_toupper
    ft_printf("\n4. Testing ft_toupper:\n");
    ft_printf("   'a' -> '%c'\n", ft_toupper('a'));
    ft_printf("   'z' -> '%c'\n", ft_toupper('z'));
    ft_printf("   '1' -> '%c'\n", ft_toupper('1'));

    // 5. ft_atoi
    ft_printf("\n5. Testing ft_atoi:\n");
    ft_printf("   \"42\" -> %d\n", ft_atoi("42"));
    ft_printf("   \"-42\" -> %d\n", ft_atoi("-42"));
    ft_printf("   \"  +123\" -> %d\n", ft_atoi("  +123"));

    print_test_header("FT_PRINTF");

    // 1. Testing decimal
    int printf_ret = ft_printf("\n1. Testing decimal: %d\n", -42);
    ft_printf("   Return value: %d\n", printf_ret);

    // 2. Testing hexadecimal
    ft_printf("\n2. Testing hexadecimal:\n");
    ft_printf("   Lowercase: %x\n", 255);
    ft_printf("   Uppercase: %X\n", 255);

    // 3. Testing pointer
    int test_var = 42;
    ft_printf("\n3. Testing pointer: %p\n", (void *)&test_var);

    // 4. Testing string with NULL
    ft_printf("\n4. Testing string with NULL: %s\n", NULL);

    // 5. Testing multiple formats
    ft_printf("\n5. Testing multiple formats: %c%s%d%%%x\n", 'A', "test", 42, 255);

    print_test_header("GET_NEXT_LINE");

    // Create a test file
    int fd = open("test_gnl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd > 0)
    {
        write(fd, "First line\nSecond line\nThird line\nFourth line\nFifth line\n", 57);
        close(fd);

        // Test regular get_next_line
        fd = open("test_gnl.txt", O_RDONLY);
        char *line;
        int line_count = 0;

        ft_printf("\nTesting regular get_next_line:\n");
        while (line_count < 5 && (line = get_next_line(fd)))
        {
            ft_printf("Line %d: %s", ++line_count, line);
            free(line);
        }
        close(fd);

        // Test get_next_line_bonus with multiple FDs
        print_test_header("GET_NEXT_LINE BONUS");
        
        int fd1 = open("test_gnl.txt", O_RDONLY);
        int fd2 = open("test_gnl.txt", O_RDONLY);
        
        ft_printf("\nTesting bonus with multiple FDs:\n");
        
        // Read alternating between fd1 and fd2
        for (int i = 0; i < 4; i++)
        {
            line = get_next_line_bonus(fd1);
            ft_printf("FD1 - Line %d: %s", i + 1, line ? line : "NULL\n");
            free(line);

            line = get_next_line_bonus(fd2);
            ft_printf("FD2 - Line %d: %s", i + 1, line ? line : "NULL\n");
            free(line);
        }

        close(fd1);
        close(fd2);
    }
    else
    {
        ft_printf("Error creating test file\n");
    }

    // Cleanup
    unlink("test_gnl.txt");  // Delete the test file
    
    // Add a final newline before the prompt
    ft_printf("\n");
    return (0);
}
