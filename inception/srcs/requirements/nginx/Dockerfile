# Alpine Lnux 3.18을 베이스 이미지로 사용
FROM alpine:3.18

# RUN: 도커파일 내에서 운영체제(Alpine)의 명령어를 사용 가능하게 함
# RUN을 사용할 때마다 하나의 'layer'가 생성이 되기 때문에 && 을 이용해 한 번에 처리하는 것이 효율적
# apk(Alpine 패키지 관리자)로 nginx, openssl을 설치
# --no-cache 플래그로 설치 후 캐시 삭제 
RUN	apk update && apk add --no-cache nginx openssl


COPY conf/default.conf /etc/nginx/http.d

# NGINX가 백그라운드에서 실행되지 않도록 하기 위해 daemon off;를 NGINX 설정 파일에 추가
RUN echo "daemon off;" >> /etc/nginx/nginx.conf

RUN openssl req \
		-x509 \
		-days 365 \
		-nodes \
		-newkey rsa:2048 \
		-keyout /etc/ssl/private/heson.42.fr.key \
		-out /etc/ssl/certs/heson.42.fr.crt \
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/OU=student/CN=www.heson.42.fr"

# 호스트 머신에서 컨테이너로 들어오는 트래픽을 위해 443 포트를 공
EXPOSE 443

# 컨테이너가 시작될 때 실행되는 명령을 지정
ENTRYPOINT [ "nginx" ]

# CMD ["nginx", "-g", "daemon off;"]