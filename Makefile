.PHONY: clean All

All:
	@echo "----------Building project:[ First_Project - Debug ]----------"
	@cd "First_Project" && "$(MAKE)" -f  "First_Project.mk"
clean:
	@echo "----------Cleaning project:[ First_Project - Debug ]----------"
	@cd "First_Project" && "$(MAKE)" -f  "First_Project.mk" clean
