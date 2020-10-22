#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_list  *list;
	t_list  *head;
	t_room *room;
	t_lem   lem;
	//t_room	*cur;
	int		fd;
	t_names	**paths;
	

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			print_error(strerror(errno));
		list = save_info(fd);
		head = list;
		head = check_errors(list, &lem);
		while (list)		// Prints out the whole input.
		{
			ft_putendl((char*)list->content);
			list = list->next;
		}
		ft_putchar('\n');
		room = room_names(head, &lem);	// Creates and initializes the big room structure.
		// cur = room;
		// while (cur)
		// {
		// 	ft_printf("name: %s\n", cur->name);
		// 	cur = cur->next;
		// }
		lem.ptr = NULL;
		build_link_tree(room, room, lem.links, &lem);
		//maybe make a check to see that all rooms have been linked and there are no "solitary" ones
		//in this case, error invalid file?
		paths = make_path_array(&lem, room);
		print_output(&lem, paths);
		//print_everything(room, &lem);
	//	lem.start = find_start_end(head, 1);
	//  lem.end = find_start_end(head, 2);
	}
	return (0);
}
