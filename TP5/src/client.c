#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> // pour inet_pton

#include "client.h"

/**
 * Fonction pour envoyer et recevoir un message depuis le serveur.
 */
int envoie_recois_message(int socketfd)
{
  char data[1024];
  memset(data, 0, sizeof(data));

  char message[1000];
  printf("Votre message (max 1000 caractères): ");
  fgets(message, sizeof(message), stdin);

  // Supprimer le \n de fgets s'il est présent
  size_t len = strlen(message);
  if (len > 0 && message[len - 1] == '\n') {
    message[len - 1] = '\0';
  }

  snprintf(data, sizeof(data), "message: %s", message);

  // Envoi
  if (write(socketfd, data, strlen(data)) < 0) {
    perror("Erreur d'écriture");
    return -1;
  }

  // Réception
  memset(data, 0, sizeof(data));
  if (read(socketfd, data, sizeof(data)) < 0) {
    perror("Erreur de lecture");
    return -1;
  }

  printf("Message reçu: %s\n", data);
  return 0;
}

int main()
{
  int socketfd;
  struct sockaddr_in server_addr;

  // Création de la socket
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Configuration du serveur (adresse IP à ajuster selon votre réseau)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);

  // 🔁 Modifie cette IP selon ton node1
  if (inet_pton(AF_INET, "10.0.67.4", &server_addr.sin_addr) <= 0) {
    perror("adresse invalide");
    exit(EXIT_FAILURE);
  }

  // Connexion au serveur
  if (connect(socketfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  printf("Connecté au serveur.\n");

  while (1) {
    if (envoie_recois_message(socketfd) < 0) {
      break;
    }
  }

  close(socketfd);
  return 0;
}
