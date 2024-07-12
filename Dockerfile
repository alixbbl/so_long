FROM ubuntu:latest

# Assurez-vous que les paquets sont à jour
RUN apt-get update && apt-get upgrade -y

# Installer les dépendances nécessaires pour votre projet
RUN apt-get install -y \
	gcc \
	make \
	libx11-dev \
	libxext-dev \
	libbsd-dev \
	xorg \
	libxrandr-dev \
	libxinerama-dev \
	libxcursor-dev \
	libxi-dev \
	zlib1g-dev \
	&& rm -rf /var/lib/apt/lists/*

# Définir le répertoire de travail dans le conteneur
WORKDIR /so_long

# Copier le contenu du dossier actuel dans le conteneur
COPY . /so_long/

# Compiler le projet lors de la construction de l'image
# Note: Assurez-vous que la compilation de mlx_linux est possible dans cet environnement
RUN make all
