#ifndef CHAT_H
#define CHAT_H

#define PORT 5000
#define MAX_CLIENTS 100
#define MAX_EVENTS 64
#define BUFFER_SIZE 4096
#define MAX_USERNAME 64
#define MAX_PASSWORD 256

typedef struct {
	int fd;
	char username[MAX_USERNAME];
	int authenticated;
	int failed_attempts;
	char input_buffer[BUFFER_SIZE];
	int input_len;
	char output_buffer[BUFFER_SIZE];
	int output_len;
	int output_pos;
} client_t;

/* auth.c */
int authenticate_user(const char *username, const char *password);
int register_user(const char *username, const char *password);

/* message.c */
void broadcast_message(const char *username, const char *text);
void save_message_log(const char *username, const char *text);
void send_message_history(int client_fd, const char *username);

/* main.c */
void send_message(client_t *client, const char *text);
void send_error(client_t *client, const char *error);
void close_client(client_t *client);

#endif
