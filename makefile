
.PHONY: clean

clean:
	find . -regextype posix-extended -regex ".*/*.out" | xargs rm -f
