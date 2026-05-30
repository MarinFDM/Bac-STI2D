import time
import math
from machine import Pin, PWM

# Déclaration des constantes
# Ports utilisés
PIN_SERVO_BASE = 5
PIN_SERVO_GAUCHE = 4
PIN_SERVO_DROIT = 17
PIN_SERVO_PINCE = 16
# consignes servo
# servo_pince : # 50° = ouverte   180° = fermée
POS_PINCE_FERMEE = 150
POS_PINCE_OUVERTE = 50
# servo_gauche : 49° = servo_pince en bas       141° = servo_pince en haut
POS_GAUCHE_HAUT = 90
POS_GAUCHE_BAS = 74
# servo_droit : 49° = servo_pince à l'arrière     134° = servo_pince à l'avant
POS_DROITE = 108
# servo_base : 0° = servo_pince à servo_droite    180° = servo_pince à servo_gauche
POS_BASE_DROITE = 90
POS_BASE_GAUCHE = 180

# Déclaration des ports
servo_base = PWM(Pin(PIN_SERVO_BASE), freq=50)
servo_gauche = PWM(Pin(PIN_SERVO_GAUCHE), freq=50)
servo_droit = PWM(Pin(PIN_SERVO_DROIT), freq=50)
servo_pince = PWM(Pin(PIN_SERVO_PINCE), freq=50)

def angle_to_rcy(angle):
    rcy = ...
    
    if rcy < 2.5:
        rcy = 2.5
    elif ...:
        rcy = ...
        
    return rcy

def position(servo, angle):
    rcy = angle_to_rcy(angle)
    servo.duty(int(1023 * rcy / 100))

def progress_to(servo, angle, duration):
    rcy = angle_to_rcy(angle)
    duty_fin = int(1023 * rcy / 100)
    duty_debut = servo.duty()
    
    if duty_fin != duty_debut:
        if duty_fin > duty_debut:
            pas = 1
        else:
            pas = -1
            
        delta_t = duration / abs(duty_fin - duty_debut)
        
        for duty in range(duty_debut, duty_fin, pas):
            servo.duty(duty)
            time.sleep(delta_t)

def bac_Normandie():
    # fermer la servo_pince
    position(servo_pince, POS_PINCE_FERMEE)
    time.sleep(1)
    # lever la servo_pince de 2cm
    position(servo_gauche, POS_GAUCHE_HAUT)
    time.sleep(1)
    # pivoter le bras de 90° sur la servo_gauche
    progress_to(servo_base, POS_BASE_GAUCHE, 1)
    time.sleep(0.5)
    # ouvrir la servo_pince de 2cm
    position(servo_pince, POS_PINCE_OUVERTE)
    time.sleep(1)
    # pivoter le bras de 90° sur la servo_droite
    progress_to(servo_base, POS_BASE_DROITE, 1)
    time.sleep(1)
    # baisser la servo_pince
    position(servo_gauche, POS_GAUCHE_BAS)

#initalisation des servo moteurs
position(servo_base, POS_BASE_DROITE)
position(servo_gauche, POS_GAUCHE_BAS)
position(servo_droit, POS_DROITE)
position(servo_pince, POS_PINCE_OUVERTE)

time.sleep(2)

bac_Normandie()
