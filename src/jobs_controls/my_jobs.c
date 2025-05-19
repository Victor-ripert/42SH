/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** jobs_command
*/

#include "minishell.h"

void cmd_jobs(jobs_t *jobs_list)
{
    for (jobs_t *job = jobs_list; job; job = job->next) {
        printf("[%d] + %s %i %s\n",
            job->job_id,
            (job->status == JOB_RUNNING) ? "running" : "suspended",
            job->pgid,
            job->command);
    }
}
