# CPP Domain Keys

A library to create database keys based on timestamp and random characters.

```
                    _____                        __          __  __                    
.----.-----.-----. |     \.-----.--------.---.-.|__|.-----. |  |/  |.-----.--.--.-----.
|  __|  _  |  _  | |  --  |  _  |        |  _  ||  ||     | |     < |  -__|  |  |__ --|
|____|   __|   __| |_____/|_____|__|__|__|___._||__||__|__| |__|\__||_____|___  |_____|
     |__|  |__|                                                           |_____|      
```

## Default Keys Format

### Timestamp Key: tskey

* 12 character, base 62
* array<char, 12> ?
* timestamp, random

### Route Key: rtkey

### API

* create_key -> ok or err
* decode_key -> timestamp

###### 2025.03.24 | dpw
