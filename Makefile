.PHONY: clean All

All:
	@echo "----------Building project:[ MeasurementsConversion - Debug ]----------"
	@cd "MeasurementsConversion" && "$(MAKE)" -f  "MeasurementsConversion.mk"
clean:
	@echo "----------Cleaning project:[ MeasurementsConversion - Debug ]----------"
	@cd "MeasurementsConversion" && "$(MAKE)" -f  "MeasurementsConversion.mk" clean
