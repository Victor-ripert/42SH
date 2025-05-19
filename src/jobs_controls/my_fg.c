/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** my_fg
*/

#include <stdio.h>
#include <sys/wait.h>
#include <sys/signal.h>
#include "minishell.h"

int cmd_fg(int job_id, jobs_t *jobs_list)
{
    jobs_t *job = find_job(job_id, jobs_list);
    int status = 0;

    if (!job) {
        fprintf(stderr, "fg: No such job.");
        return FAILURE;
    }
    printf("%s\n", job->command);
    if (job->status == JOB_STOPPED) {
        kill(job->pgid, SIGCONT);
        waitpid(job->pgid, &status, WUNTRACED);
    } else
        waitpid(job->pgid, &status, 0);
    if (WIFSTOPPED(status)) {
        job->status = JOB_STOPPED;
        printf("Suspended");
    } else
        remove_job(job->job_id, jobs_list);
    return (job->pgid == -1) ? FAILURE : handle_signal(status);
}
