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

static void print_stack_content(t_stack *stack, const char *message)
{
    ft_printf("%s", message);
    while (stack)
    {
        ft_printf("%s -> ", (char *)stack->content);
        stack = stack->next;
    }
    ft_printf("NULL\n");
}

static void putstr_stdout(void *content)
{
    ft_putstr_fd((char *)content, 1);
}

static void *map_function(void *content)
{
    char *str = (char *)content;
    char *new_str = malloc(strlen(str) + 8);
    if (new_str)
        sprintf(new_str, "mapped_%s", str);
    return new_str;
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
    
    print_test_header("STACK FUNCTIONS");

    // 1. Testing ft_stacknew
    ft_printf("\n1. Testing ft_stacknew:\n");
    char *stack_content = "Stack Test Content";
    t_stack *stack_node = ft_stacknew(stack_content);
    ft_printf("   Node content: %s\n", (char *)stack_node->content);
    ft_printf("   Next pointer: %p\n", (void *)stack_node->next);
    ft_printf("   Prev pointer: %p\n", (void *)stack_node->prev);

    // 2. Testing ft_stackadd_front
    ft_printf("\n2. Testing ft_stackadd_front:\n");
    t_stack *stack = NULL;
    ft_stackadd_front(&stack, ft_stacknew("Third"));
    ft_stackadd_front(&stack, ft_stacknew("Second"));
    ft_stackadd_front(&stack, ft_stacknew("First"));
    print_stack_content(stack, "   Stack after additions: ");

    // 3. Testing ft_stackadd_back
    ft_printf("\n3. Testing ft_stackadd_back:\n");
    ft_stackadd_back(&stack, ft_stacknew("Fourth"));
    ft_stackadd_back(&stack, ft_stacknew("Fifth"));
    print_stack_content(stack, "   Stack after back additions: ");

    // 4. Testing ft_stacksize
    ft_printf("\n4. Testing ft_stacksize:\n");
    ft_printf("   Stack size: %d\n", ft_stacksize(stack));

    // 5. Testing ft_stacklast
    ft_printf("\n5. Testing ft_stacklast:\n");
    t_stack *last = ft_stacklast(stack);
    ft_printf("   Last node content: %s\n", (char *)last->content);

    // 6. Testing ft_stackiter
    ft_printf("\n6. Testing ft_stackiter:\n");
    ft_printf("   Iterating through stack: ");
    ft_stackiter(stack, putstr_stdout);
    ft_printf("\n");

    // 7. Testing ft_stackmap
    ft_printf("\n7. Testing ft_stackmap:\n");
    
    t_stack *mapped_stack = ft_stackmap(stack, map_function, free);
    print_stack_content(mapped_stack, "   Mapped stack: ");

    // 8. Testing prev pointers
    ft_printf("\n8. Testing prev pointers:\n");
    t_stack *current = ft_stacklast(stack);
    ft_printf("   Reverse iteration: ");
    while (current)
    {
        ft_printf("%s -> ", (char *)current->content);
        current = current->prev;
    }
    ft_printf("NULL\n");

    // 9. Testing ft_stackdelone
    ft_printf("\n9. Testing ft_stackdelone:\n");
    t_stack *to_delete = stack->next;
    stack->next = to_delete->next;
    if (to_delete->next)
        to_delete->next->prev = stack;
    ft_printf("   Deleting node with content: %s\n", (char *)to_delete->content);
    ft_stackdelone(to_delete, NULL);  // Using NULL since we're using string literals
    print_stack_content(stack, "   Stack after deletion: ");

    // 10. Testing ft_stackclear
    ft_printf("\n10. Testing ft_stackclear:\n");
    ft_printf("   Clearing mapped stack...\n");
    ft_stackclear(&mapped_stack, free);
    ft_printf("   Mapped stack after clear (should be nil): %p\n", (void *)mapped_stack);
    
    // Clean up the original stack (with string literals, so no content freeing needed)
    ft_stackclear(&stack, NULL);

    // Add a final newline before the prompt
    ft_printf("\n");
    return (0);
}