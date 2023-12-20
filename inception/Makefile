DOCKER_COMPOSE_YML		= srcs/docker-compose.yml
DOCKER_DATA_DIR			= $(HOME)/data

DOMAIN					= "127.0.0.1 heson.42.fr"

all : run

run : $(DOCKER_DATA_DIR) $(DOMAIN)
	docker-compose -f $(DOCKER_COMPOSE_YML) up -d --build
up :
	docker-compose -f $(DOCKER_COMPOSE_YML) up -d

down:
	docker-compose -f $(DOCKER_COMPOSE_YML) down

$(DOCKER_DATA_DIR) :
	@mkdir -p $(DOCKER_DATA_DIR)/DB
	@mkdir -p $(DOCKER_DATA_DIR)/WP

$(DOMAIN) :
	@if [ ! "$$(sudo grep $(DOMAIN) /etc/hosts)" ]; then sudo sh -c 'echo $(DOMAIN) >> /etc/hosts'; fi


fclean :
	docker-compose -f $(DOCKER_COMPOSE_YML) down --volumes
	docker system prune -a
	sudo rm -rf $(DOCKER_DATA_DIR)

clean : down

.PHONY	: all build up down clean fclean