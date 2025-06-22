# Display Board Support

This project supports multiple display boards:

## Supported Boards

### 1. LilyGO T-RGB (Original)
- **Environment**: `display`
- **Board**: LilyGo T-RGB
- **Features**: 
  - Auto-detection via GPIO pin 8
  - Touch support (FT3267, CST820, GT911)
  - 2.1" or 2.8" variants
  - Built-in battery management

### 2. Waveshare ESP32-S3 Touch LCD 2.1"
- **Environment**: `display-waveshare`
- **Board**: Waveshare-ESP32S3-Touch-LCD-2.1
- **Features**:
  - 2.1" 480x480 RGB LCD
  - Capacitive touch (CST820, GT911)
  - ESP32-S3 with 16MB Flash, 8MB PSRAM
  - I2C expansion chip (TCA9554PWR)

## Building and Flashing

### For LilyGO T-RGB:
```bash
pio run -e display
pio run -e display -t upload
```

### For Waveshare ESP32-S3 Touch LCD:
```bash
pio run -e display-waveshare
pio run -e display-waveshare -t upload
```

## Automatic Detection

The firmware automatically detects which display board is connected:

1. **LilyGO Detection**: Checks GPIO pin 8 (pull-down)
   - If HIGH: Uses LilyGO T-RGB driver
   - If LOW: Falls back to Waveshare driver

2. **Waveshare Fallback**: If LilyGO is not detected, the Waveshare driver is used

## Hardware Differences

| Feature | LilyGO T-RGB | Waveshare ESP32-S3 |
|---------|--------------|-------------------|
| Display Size | 2.1" / 2.8" | 2.1" |
| Resolution | 480x480 | 480x480 |
| Touch Controller | FT3267/CST820/GT911 | CST820/GT911 |
| I2C Expansion | XL9555 | TCA9554PWR |
| Flash/PSRAM | 16MB/8MB | 16MB/8MB |
| Detection Pin | GPIO 8 | N/A (fallback) |

## Troubleshooting

1. **Display not working**: Check if you're using the correct environment for your board
2. **Touch not responding**: The touch controller is auto-detected, ensure proper wiring
3. **Build errors**: Make sure all required libraries are installed (automatically handled by PlatformIO)
4. **"Failed to initialize Waveshare ESP32-S3 Touch LCD" error**: 
   - Check I2C connections (GPIO7=SCL, GPIO15=SDA)
   - Verify TCA9554PWR GPIO expander communication
   - Check serial monitor for detailed I2C error messages
5. **"Touch chip not found" warning**: This is normal if touch hardware isn't present, display will still work
6. **"TCA9554PWR I2C write/read failure"**: 
   - Verify I2C bus initialization
   - Check for I2C address conflicts
   - Ensure proper power supply (5V via USB-C)

## Pin Configurations

Pin configurations are automatically handled by each board's driver. See:
- `src/display/drivers/LilyGo-T-RGB/utilities.h` for LilyGO pins
- `src/display/drivers/Waveshare/utilities.h` for Waveshare pins 