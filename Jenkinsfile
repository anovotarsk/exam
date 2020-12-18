pipeline {
    agent any
    
    environment {
        registryCredential = 'docker_hub'
        dockerImage = ''
    }

    stages {
        stage('Build') {
            steps {
                echo 'Building...'
                sh 'cmake . -Bbuild -Wdev -Werror=dev && cmake --build ./build'
            }
        }
        stage('Test') {
            steps {
                echo 'Testing...'
                sh 'cd build/ && ctest -T Test'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploying....'
            }
        }
        stage('Docker Publosh') {
            agent any
            
            when {
                expression {
                    currentBuild.result == null || currentBuild.result == 'SUCCESS'
                }
            }
            
            steps {
                echo "Application Publishing"
                checkout scm
                script {
                    def customImage = docker.build("anovotarsk/lab5:${env.BUILD_ID}")
                    docker.withRegistry('', registryCredential ) {
                        customImage.push()
                    }
                }
            }
        }
    }
    post {
        always {
            xunit (
                //thresholds: [ skipped(failureThreshold: '0'), failed(failureThreshold: '0') ],
                tools: [ CTest(pattern: 'build/Testing/**/Test.xml') ]
            )
        }
    }
}
