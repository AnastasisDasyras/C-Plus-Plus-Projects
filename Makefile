.PHONY: clean All

All:
	@echo "----------Building project:[ LoopsEverywhere - Debug ]----------"
	@cd "LoopsEverywhere" && "$(MAKE)" -f  "LoopsEverywhere.mk"
clean:
	@echo "----------Cleaning project:[ LoopsEverywhere - Debug ]----------"
	@cd "LoopsEverywhere" && "$(MAKE)" -f  "LoopsEverywhere.mk" clean
