MEASURE=	common/measure

all:

$(MEASURE):	$(MEASURE).c
	@make -s -C common

test:		$(MEASURE)
	@[ -f challenge01/solution.cpp ] && (echo "Testing challenge01"; cd challenge01; make -s test)
	@[ -f challenge02/solution.cpp ] && (echo "Testing challenge02"; cd challenge02; make -s test)
