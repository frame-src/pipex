#include "../../include/pipex_bonus.h"

void	init_files(struct files *file)
{
	file->infile = -1;
	file->outfile = -1;
	file->fileds[1] = -1;
	file->fileds[0] = -1;
	file->status = -1;
}

void	init_pipe(struct files *file)
{
	if (pipe(file->fileds) == -1)
		perror("Pipe");
}

void	initialize_paths(char **envp, struct paths *path)
{
	path->function_pointer = &extract_path;
	path->split = ft_split(envp[find_path(envp)] + 5, ':');
}

void	init_counters(struct counters *counter, int argc)
{
	counter->i = 2;
	counter->argc = argc;
}

void	initialize_args(char **argv, int i, struct paths *path, int argc)
{
	if (argv[i][0] == 0)
	{
		path->args = 0;
		path->arg = 0;
	}
	else
	{
		if (i != argc - 1)
		{
			path->args = ft_split(*(argv + i), ' ');
			path->arg = (*path->function_pointer)(path->split, path->args[0]);
		}
	}
}
