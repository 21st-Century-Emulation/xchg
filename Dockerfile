FROM drogonframework/drogon:latest as build

WORKDIR /app

COPY CMakeLists.txt main.cc ./
COPY controllers/ controllers/
RUN mkdir build
WORKDIR /app/build
RUN cmake ..
RUN make

FROM drogonframework/drogon:latest as runtime

COPY --from=build /app/build/XCHG .

ENTRYPOINT [ "./XCHG" ]