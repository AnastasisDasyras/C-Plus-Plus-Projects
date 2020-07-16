.PHONY: clean All

All:
	@echo "----------Building project:[ ClassyProject - Debug ]----------"
	@cd "ClassyProject" && "$(MAKE)" -f  "ClassyProject.mk"
clean:
	@echo "----------Cleaning project:[ ClassyProject - Debug ]----------"
	@cd "ClassyProject" && "$(MAKE)" -f  "ClassyProject.mk" clean
