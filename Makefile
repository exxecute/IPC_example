all: $(ALL_OBJS)
	$(CXX) receiver.cc -o receiver.elf
	$(CXX) sender.cc -o sender.elf
	
clean:
	@rm -rf *.elf
