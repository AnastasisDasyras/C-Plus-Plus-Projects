.PHONY: clean All

All:
	@echo "----------Building project:[ DaCipher - Debug ]----------"
	@cd "DaCipher" && "$(MAKE)" -f  "DaCipher.mk"
clean:
	@echo "----------Cleaning project:[ DaCipher - Debug ]----------"
	@cd "DaCipher" && "$(MAKE)" -f  "DaCipher.mk" clean
