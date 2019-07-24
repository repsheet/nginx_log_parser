.PHONY: build
build:
	docker build -t log_parser .

.PHONY: run
run:
	docker run --network threat_intel log_parser
