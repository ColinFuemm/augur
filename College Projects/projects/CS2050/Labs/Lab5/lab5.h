#include <stdio.h>
#include <stdlib.h>

#define SECT_F
typedef struct {
	unsigned long accountNumber;
	float accountWorth;
	int daysActive;
} Client;

unsigned long getAN(Client *client);
void setAN(Client *client, unsigned long AN);
float getAW(Client *client);
void setAW(Client *client, float AW);
int getDays(Client *client);
void setDays(Client *client, int days);
void printClientArray(Client *clients);
Client* loadClientsFromFile(const char *filename);
Client* getOldestAccount(Client *clients);
Client* getClientByAN(Client *clients, unsigned long AN);
double sumAccountWorth(Client *clients);

int getArraySize(Client *array);