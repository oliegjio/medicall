from django.shortcuts import render
from django.http import HttpResponse

from django.contrib.auth import login, authenticate
from website.forms import UserCreationForm
from django.shortcuts import render, redirect

from website.models import User


def index(request):
    return render(request, 'home.html')


def signup(request):
    if request.method == 'POST':
        form = UserCreationForm(request.POST)

        if form.is_valid():
            form.save()
            username = form.cleaned_data.get('username')
            raw_password = form.cleaned_data.get('password')
            user = authenticate(request, username=username, password=raw_password) 
            login(request, user)
            return redirect('http://' + request.get_host() + '/website')
    else:
        form = UserCreationForm()

    return render(request, 'registration/signup.html', {'form': form})


def user(request, id):
    try:
        user = User.objects.get(id=id)
    except User.DoesNotExist:
        return HttpResponse('This user does not exist!')

    return render(request, 'user.html', {'user': user})
