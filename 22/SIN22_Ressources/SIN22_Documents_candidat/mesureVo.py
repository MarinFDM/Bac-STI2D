from machine import Pin, ADC

PIN_CAPTEUR_DISTANCE = 36

capteur_distance = ADC(Pin(PIN_CAPTEUR_DISTANCE))
capteur_distance.atten(ADC.ATTN_11DB)
capteur_distance.width(ADC.WIDTH_10BIT)

vo = capteur_distance.read_uv() / 1_000_000
print(vo,"V")