from django.conf.urls import url, include
# from jwt_auth.views import obtain_jwt_token, refresh_jwt_token
from jwt_auth.views import obtain_jwt_token

from . import views

urlpatterns = [
    url(r'^$', views.index, name='index'),
    url(r'token-auth/', obtain_jwt_token),
    # url(r'token-refresh/', refresh_jwt_token),
    url(r'^accounts/', include('django.contrib.auth.urls')),
    url(r'^signup$', views.signup, name='signup'),
    url(r'^user/(?P<id>[0-9]+)', views.user, name='user')
]
