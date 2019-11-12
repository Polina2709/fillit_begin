//
// Created by Taisha Myrcella on 11/11/2019.
//

#import "fillit.h"

t_tetri     replace_coords(t_tetri result, int min_x, int min_y)
{
    int x;
    int y;
    int i;

    if (min_x <= 0 && min_y <= 0)
        return (result);
    i = 0;
    while (i < 8)
    {
        if ((min_x > 0) && (i % 2 == 0))
            result.coords[i] = result.coords[i] - min_x;
        if ((min_y > 0) && (i % 2 != 0))
            result.coords[i + 1] = result.coords[i + 1] - min_y;
        i++;
    }
    return (result);
}


t_tetri    find_min_coords(t_tetri result)
{
    int i;
    int j;
    int min_x;
    int min_y;

    j = 1;
    i = 0;
    min_x = result.coords[i];
    min_y = result.coords[j];
    while (i < 8)
    {
        if (result.coords[i] > result.coords[i + 2])
            min_x = result.coords[i + 2];
        if (result.coords[j] > result.coords[j + 2])
            min_y = result.coords[j + 2];
        i += 2;
        j += 2;
    }
    replace_coords(result, min_x, min_y);
    return result;
}

/*t_tetri    create_node(t_tetri *result)
{
    t_tetri *res;

    res = NULL;
    res = malloc(sizeof(t_tetri));
    res->next = NULL;
    return (*res);
}

t_tetri    add_node(t_tetri *result)
{
    t_tetri *res;
    t_tetri *tmp;

    tmp = create_node(result);
    if (result == NULL) {
        result = tmp;
        result->name = 'A';
    }
    else {
        res = result;
        while (res->next != NULL) {
            res = res->next;
            res->name = res->next->name++;
        }
    }
    res->next = tmp;
    return (*result);
}
*/

t_tetri    save_coords(char *line)
{
    t_tetri     *result;
    int         i;
    int         j;

    i = 0;
    j = 0;
    add_node(result);
    while (line[i] != '\0')
    {
        if (line[i] == '#')
        {
            result->coords[j] = i % 5;
            result->coords[j + 1] = i / 5;
            j += 2;
        }
        i++;

    }
    find_min_coords(*result);
    return (*result);
}