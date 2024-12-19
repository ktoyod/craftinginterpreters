RUN_CONTEXT ?= docker compose exec java

up:
	docker compose up -d
	docker compose logs

build:
	docker compose build

bash:
	$(RUN_CONTEXT) bash

compile:
	$(RUN_CONTEXT) javac Main.java

run: compile
	$(RUN_CONTEXT) java Main
