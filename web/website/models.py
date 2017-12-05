from django.db import models

from django.contrib.auth.models import (
    BaseUserManager, AbstractBaseUser
)


class UserManager(BaseUserManager):
    def create_user(self, email, password=None):
        if not email:
            raise ValueError('Users must have an email address')

        user = self.model(
            email=self.normalize_email(email),
        )

        user.set_password(password)
        user.save(using=self._db)
        return user

    def create_superuser(self, email, password):
        user = self.create_user(
            email,
            password=password,
        )
        user.admin = True
        user.save(using=self._db)
        return user


class User(AbstractBaseUser):
    objects = UserManager()

    email = models.EmailField(
        verbose_name='email address',
        max_length=255,
        unique=True,
    )
    username = models.CharField(max_length=25, unique=True)
    admin = models.BooleanField(default=False)
    doctor = models.BooleanField(default=False)
    patient = models.BooleanField(default=False)

    birth_date = models.DateField(null=True, blank=True)
    location = models.CharField(max_length=255, null=True, blank=True)
    sex = models.NullBooleanField(default=False, null=True, blank=True)
    weight = models.DecimalField(decimal_places=2, max_digits=6, null=True, blank=True)
    height = models.DecimalField(decimal_places=2, max_digits=6, null=True, blank=True)
    blood_type = models.CharField(max_length=3, null=True, blank=True)
    phone_number = models.CharField(max_length=20, null=True, blank=True)
    speciality = models.CharField(max_length=100, null=True, blank=True)
    social = models.CharField(max_length=100, null=True, blank=True)

    USERNAME_FIELD = 'username'
    REQUIRED_FIELDS = ['email']

    @property
    def is_admin(self):
        "Is the user a admin member?"
        return self.admin

class MedicalRecord(models.Model):
    patient = models.OneToOneField(
        User, 
        on_delete=models.CASCADE
    )

class MedicalRecordArticle(models.Model):
    medical_record = models.ForeignKey(
        MedicalRecord,
        on_delete=models.CASCADE
    )
    title = models.CharField(max_length=100)
    start_date = models.DateField()
    end_date = models.DateField()
    comments = models.TextField()
    medicaments = models.TextField()
    
class Recomendation(models.Model):
    patient = models.ForeignKey(User, on_delete=models.CASCADE)
    date = models.DateField()
    title = models.CharField(max_length=100)
    text = models.TextField()
    doctor = models.OneToOneField(
        User,
        on_delete=models.CASCADE,
        related_name='doctor_id'
    )

class Disease(models.Model):
    name = models.CharField(max_length=100)
    simptoms = models.TextField()
    description = models.TextField()
