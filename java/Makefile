RUN_CONTEXT ?= docker compose exec java

up:
	docker compose up -d
	docker compose logs

build:
	docker compose build

bash:
	$(RUN_CONTEXT) bash

compile:
	$(RUN_CONTEXT) javac com/craftinginterpreters/lox/Lox.java

run: compile
	$(RUN_CONTEXT) java com/craftinginterpreters/lox/Lox

run/%: compile
	$(RUN_CONTEXT) java com/craftinginterpreters/lox/Lox $*


tool/compile:
	$(RUN_CONTEXT) javac com/craftinginterpreters/tool/GenerateAst.java

tool/run: tool/compile
	$(RUN_CONTEXT) java com/craftinginterpreters/tool/GenerateAst com/craftinginterpreters/lox

AstPrinter/compile:
	$(RUN_CONTEXT) javac com/craftinginterpreters/lox/AstPrinter.java

AstPrinter/run: AstPrinter/compile
	$(RUN_CONTEXT) java com/craftinginterpreters/lox/AstPrinter
