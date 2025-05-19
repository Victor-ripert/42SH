/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_bg
*/

#include <stdio.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include "minishell.h"

int cmd_bg(int job_id, jobs_t *jobs_list)
{
    jobs_t *job = find_job(job_id, jobs_list);

    if (!job) {
        fprintf(stderr, "bg: No such job.");
        return FAILURE;
    }
    printf("[%d] %s &\n", job->job_id, job->command);
    kill(-job->pgid, SIGCONT);
    job->status = JOB_RUNNING;
    return SUCCESS;
}
